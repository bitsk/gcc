;; Machine description for RISC-V atomic operations.
;; Copyright (C) 2011-2020 Free Software Foundation, Inc.
;; Contributed by Andrew Waterman (andrew@sifive.com).
;; Based on MIPS target for GNU compiler.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(define_c_enum "unspec" [
  UNSPEC_COMPARE_AND_SWAP
  UNSPEC_COMPARE_AND_SWAP_SUBWORD
  UNSPEC_SYNC_OLD_OP
  UNSPEC_SYNC_OLD_OP_SUBWORD
  UNSPEC_SYNC_EXCHANGE
  UNSPEC_SYNC_EXCHANGE_SUBWORD
  UNSPEC_ATOMIC_STORE
  UNSPEC_MEMORY_BARRIER
])

(define_code_iterator any_atomic [plus ior xor and])
(define_code_attr atomic_optab
  [(plus "add") (ior "or") (xor "xor") (and "and")])

;; Memory barriers.

(define_expand "mem_thread_fence"
  [(match_operand:SI 0 "const_int_operand" "")] ;; model
  ""
{
  if (INTVAL (operands[0]) != MEMMODEL_RELAXED)
    {
      rtx mem = gen_rtx_MEM (BLKmode, gen_rtx_SCRATCH (Pmode));
      MEM_VOLATILE_P (mem) = 1;
      emit_insn (gen_mem_thread_fence_1 (mem, operands[0]));
    }
  DONE;
})

;; Until the RISC-V memory model (hence its mapping from C++) is finalized,
;; conservatively emit a full FENCE.
(define_insn "mem_thread_fence_1"
  [(set (match_operand:BLK 0 "" "")
	(unspec:BLK [(match_dup 0)] UNSPEC_MEMORY_BARRIER))
   (match_operand:SI 1 "const_int_operand" "")] ;; model
  ""
  "fence\tiorw,iorw")

;; Atomic memory operations.

;; Implement atomic stores with amoswap.  Fall back to fences for atomic loads.
(define_insn "atomic_store<mode>"
  [(set (match_operand:GPR 0 "riscv_sync_memory_operand" "=A")
    (unspec_volatile:GPR
      [(match_operand:GPR 1 "reg_or_0_operand" "rJ")
       (match_operand:SI 2 "const_int_operand")]      ;; model
      UNSPEC_ATOMIC_STORE))]
  "TARGET_ATOMIC"
  "%F2amoswap.<amo>%A2 zero,%z1,%0"
  [(set (attr "length") (const_int 8))
   (set_attr "type" "atomic")])

(define_insn "atomic_<atomic_optab><mode>"
  [(set (match_operand:GPR 0 "riscv_sync_memory_operand" "+A")
	(unspec_volatile:GPR
	  [(any_atomic:GPR (match_dup 0)
		     (match_operand:GPR 1 "reg_or_0_operand" "rJ"))
	   (match_operand:SI 2 "const_int_operand")] ;; model
	 UNSPEC_SYNC_OLD_OP))]
  "TARGET_ATOMIC"
  "%F2amo<insn>.<amo>%A2 zero,%z1,%0"
  [(set (attr "length") (const_int 8))
   (set_attr "type" "atomic")])

(define_insn "atomic_fetch_<atomic_optab><mode>"
  [(set (match_operand:GPR 0 "register_operand" "=&r")
	(match_operand:GPR 1 "riscv_sync_memory_operand" "+A"))
   (set (match_dup 1)
	(unspec_volatile:GPR
	  [(any_atomic:GPR (match_dup 1)
		     (match_operand:GPR 2 "reg_or_0_operand" "rJ"))
	   (match_operand:SI 3 "const_int_operand")] ;; model
	 UNSPEC_SYNC_OLD_OP))]
  "TARGET_ATOMIC"
  "%F3amo<insn>.<amo>%A3 %0,%z2,%1"
  [(set (attr "length") (const_int 8))
   (set_attr "type" "atomic")])

(define_insn "subword_atomic_fetch_strong_<atomic_optab>"
  [(set (match_operand:SI 0 "register_operand" "=&r")		   ;; old value at mem
	(match_operand:SI 1 "memory_operand" "+A"))		   ;; mem location
   (set (match_dup 1)
	(unspec_volatile:SI
	  [(any_atomic:SI (match_dup 1)
		     (match_operand:SI 2 "register_operand" "rI")) ;; value for op
	   (match_operand:SI 3 "register_operand" "rI")]	   ;; mask
	 UNSPEC_SYNC_OLD_OP_SUBWORD))
    (match_operand:SI 4 "register_operand" "rI")		   ;; not_mask
    (clobber (match_scratch:SI 5 "=&r"))			   ;; tmp_1
    (clobber (match_scratch:SI 6 "=&r"))]			   ;; tmp_2
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
  {
    return "1:\;"
	   "lr.w.aq\t%0, %1\;"
	   "<insn>\t%5, %0, %2\;"
	   "and\t%5, %5, %3\;"
	   "and\t%6, %0, %4\;"
	   "or\t%6, %6, %5\;"
	   "sc.w.rl\t%5, %6, %1\;"
	   "bnez\t%5, 1b";
  }
  [(set (attr "length") (const_int 28))])

(define_expand "atomic_fetch_nand<mode>"
  [(match_operand:SHORT 0 "register_operand")			      ;; old value at mem
   (not:SHORT (and:SHORT (match_operand:SHORT 1 "memory_operand")     ;; mem location
			 (match_operand:SHORT 2 "reg_or_0_operand"))) ;; value for op
   (match_operand:SI 3 "const_int_operand")]			      ;; model
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
{
  /* We have no QImode/HImode atomics, so form a mask, then use
     subword_atomic_fetch_strong_nand to implement a LR/SC version of the
     operation. */

  /* Logic duplicated in gcc/libgcc/config/riscv/atomic.c for use when inlining
     is disabled */

  rtx old = gen_reg_rtx (SImode);
  rtx mem = operands[1];
  rtx value = operands[2];
  rtx aligned_mem = gen_reg_rtx (SImode);
  rtx shift = gen_reg_rtx (SImode);
  rtx mask = gen_reg_rtx (SImode);
  rtx not_mask = gen_reg_rtx (SImode);

  riscv_subword_address (mem, &aligned_mem, &shift, &mask, &not_mask);

  rtx shifted_value = gen_reg_rtx (SImode);
  riscv_lshift_subword (<MODE>mode, value, shift, &shifted_value);

  emit_insn (gen_subword_atomic_fetch_strong_nand (old, aligned_mem,
						   shifted_value,
						   mask, not_mask));

  emit_move_insn (old, gen_rtx_ASHIFTRT (SImode, old,
					 gen_lowpart (QImode, shift)));

  emit_move_insn (operands[0], gen_lowpart (<MODE>mode, old));

  DONE;
})

(define_insn "subword_atomic_fetch_strong_nand"
  [(set (match_operand:SI 0 "register_operand" "=&r")			  ;; old value at mem
	(match_operand:SI 1 "memory_operand" "+A"))			  ;; mem location
   (set (match_dup 1)
	(unspec_volatile:SI
	  [(not:SI (and:SI (match_dup 1)
			   (match_operand:SI 2 "register_operand" "rI"))) ;; value for op
	   (match_operand:SI 3 "register_operand" "rI")]		  ;; mask
	 UNSPEC_SYNC_OLD_OP_SUBWORD))
    (match_operand:SI 4 "register_operand" "rI")			  ;; not_mask
    (clobber (match_scratch:SI 5 "=&r"))				  ;; tmp_1
    (clobber (match_scratch:SI 6 "=&r"))]				  ;; tmp_2
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
  {
    return "1:\;"
	   "lr.w.aq\t%0, %1\;"
	   "and\t%5, %0, %2\;"
	   "not\t%5, %5\;"
	   "and\t%5, %5, %3\;"
	   "and\t%6, %0, %4\;"
	   "or\t%6, %6, %5\;"
	   "sc.w.rl\t%5, %6, %1\;"
	   "bnez\t%5, 1b";
  }
  [(set (attr "length") (const_int 32))])

(define_expand "atomic_fetch_<atomic_optab><mode>"
  [(match_operand:SHORT 0 "register_operand")			 ;; old value at mem
   (any_atomic:SHORT (match_operand:SHORT 1 "memory_operand")	 ;; mem location
		     (match_operand:SHORT 2 "reg_or_0_operand")) ;; value for op
   (match_operand:SI 3 "const_int_operand")]			 ;; model
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
{
  /* We have no QImode/HImode atomics, so form a mask, then use
     subword_atomic_fetch_strong_<mode> to implement a LR/SC version of the
     operation. */

  /* Logic duplicated in gcc/libgcc/config/riscv/atomic.c for use when inlining
     is disabled */

  rtx old = gen_reg_rtx (SImode);
  rtx mem = operands[1];
  rtx value = operands[2];
  rtx aligned_mem = gen_reg_rtx (SImode);
  rtx shift = gen_reg_rtx (SImode);
  rtx mask = gen_reg_rtx (SImode);
  rtx not_mask = gen_reg_rtx (SImode);

  riscv_subword_address (mem, &aligned_mem, &shift, &mask, &not_mask);

  rtx shifted_value = gen_reg_rtx (SImode);
  riscv_lshift_subword (<MODE>mode, value, shift, &shifted_value);

  emit_insn (gen_subword_atomic_fetch_strong_<atomic_optab> (old, aligned_mem,
							     shifted_value,
							     mask, not_mask));

  emit_move_insn (old, gen_rtx_ASHIFTRT (SImode, old,
					 gen_lowpart (QImode, shift)));

  emit_move_insn (operands[0], gen_lowpart (<MODE>mode, old));

  DONE;
})

(define_insn "atomic_exchange<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=&r")
	(unspec_volatile:GPR
	  [(match_operand:GPR 1 "riscv_sync_memory_operand" "+A")
	   (match_operand:SI 3 "const_int_operand")] ;; model
	  UNSPEC_SYNC_EXCHANGE))
   (set (match_dup 1)
	(match_operand:GPR 2 "register_operand" "0"))]
  "TARGET_ATOMIC"
  "%F3amoswap.<amo>%A3 %0,%z2,%1"
  [(set (attr "length") (const_int 8))
   (set_attr "type" "atomic")])

(define_expand "atomic_exchange<mode>"
  [(match_operand:SHORT 0 "register_operand") ;; old value at mem
   (match_operand:SHORT 1 "memory_operand")   ;; mem location
   (match_operand:SHORT 2 "register_operand") ;; value
   (match_operand:SI 3 "const_int_operand")]  ;; model
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
{
  rtx old = gen_reg_rtx (SImode);
  rtx mem = operands[1];
  rtx value = operands[2];
  rtx aligned_mem = gen_reg_rtx (SImode);
  rtx shift = gen_reg_rtx (SImode);
  rtx mask = gen_reg_rtx (SImode);
  rtx not_mask = gen_reg_rtx (SImode);

  riscv_subword_address (mem, &aligned_mem, &shift, &mask, &not_mask);

  rtx shifted_value = gen_reg_rtx (SImode);
  riscv_lshift_subword (<MODE>mode, value, shift, &shifted_value);

  emit_insn (gen_subword_atomic_exchange_strong (old, aligned_mem,
						 shifted_value, not_mask));

  emit_move_insn (old, gen_rtx_ASHIFTRT (SImode, old,
					 gen_lowpart (QImode, shift)));

  emit_move_insn (operands[0], gen_lowpart (<MODE>mode, old));
  DONE;
})

(define_insn "subword_atomic_exchange_strong"
  [(set (match_operand:SI 0 "register_operand" "=&r")	 ;; old value at mem
	(match_operand:SI 1 "memory_operand" "+A"))	 ;; mem location
   (set (match_dup 1)
	(unspec_volatile:SI
	  [(match_operand:SI 2 "reg_or_0_operand" "rI")  ;; value
	   (match_operand:SI 3 "reg_or_0_operand" "rI")] ;; not_mask
      UNSPEC_SYNC_EXCHANGE_SUBWORD))
    (clobber (match_scratch:SI 4 "=&r"))]		 ;; tmp_1
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
  {
    return "1:\;"
	   "lr.w.aq\t%0, %1\;"
	   "and\t%4, %0, %3\;"
	   "or\t%4, %4, %2\;"
	   "sc.w.rl\t%4, %4, %1\;"
	   "bnez\t%4, 1b";
  }
  [(set (attr "length") (const_int 20))])

(define_insn "atomic_cas_value_strong<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=&r")
	(match_operand:GPR 1 "riscv_sync_memory_operand" "+A"))
   (set (match_dup 1)
	(unspec_volatile:GPR [(match_operand:GPR 2 "reg_or_0_operand" "rJ")
			      (match_operand:GPR 3 "reg_or_0_operand" "rJ")
			      (match_operand:SI 4 "const_int_operand")  ;; mod_s
			      (match_operand:SI 5 "const_int_operand")] ;; mod_f
	 UNSPEC_COMPARE_AND_SWAP))
   (clobber (match_scratch:GPR 6 "=&r"))]
  "TARGET_ATOMIC"
  "%F5 1: lr.<amo>%A5 %0,%1; bne %0,%z2,1f; sc.<amo>%A4 %6,%z3,%1; bnez %6,1b; 1:"
  [(set (attr "length") (const_int 20))
   (set_attr "type" "atomic")])

(define_expand "atomic_compare_and_swap<mode>"
  [(match_operand:SI 0 "register_operand" "")   ;; bool output
   (match_operand:GPR 1 "register_operand" "")  ;; val output
   (match_operand:GPR 2 "riscv_sync_memory_operand" "")    ;; memory
   (match_operand:GPR 3 "reg_or_0_operand" "")  ;; expected value
   (match_operand:GPR 4 "reg_or_0_operand" "")  ;; desired value
   (match_operand:SI 5 "const_int_operand" "")  ;; is_weak
   (match_operand:SI 6 "const_int_operand" "")  ;; mod_s
   (match_operand:SI 7 "const_int_operand" "")] ;; mod_f
  "TARGET_ATOMIC"
{
  emit_insn (gen_atomic_cas_value_strong<mode> (operands[1], operands[2],
						operands[3], operands[4],
						operands[6], operands[7]));

  rtx compare = operands[1];
  if (operands[3] != const0_rtx)
    {
      rtx difference = gen_rtx_MINUS (<MODE>mode, operands[1], operands[3]);
      compare = gen_reg_rtx (<MODE>mode);
      emit_insn (gen_rtx_SET (compare, difference));
    }

  if (word_mode != <MODE>mode)
    {
      rtx reg = gen_reg_rtx (word_mode);
      emit_insn (gen_rtx_SET (reg, gen_rtx_SIGN_EXTEND (word_mode, compare)));
      compare = reg;
    }

  emit_insn (gen_rtx_SET (operands[0], gen_rtx_EQ (SImode, compare, const0_rtx)));
  DONE;
})

(define_expand "atomic_compare_and_swap<mode>"
  [(match_operand:SI 0 "register_operand")    ;; bool output
   (match_operand:SHORT 1 "register_operand") ;; val output
   (match_operand:SHORT 2 "memory_operand")   ;; memory
   (match_operand:SHORT 3 "reg_or_0_operand") ;; expected value
   (match_operand:SHORT 4 "reg_or_0_operand") ;; desired value
   (match_operand:SI 5 "const_int_operand")   ;; is_weak
   (match_operand:SI 6 "const_int_operand")   ;; mod_s
   (match_operand:SI 7 "const_int_operand")]  ;; mod_f
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
{
  emit_insn (gen_atomic_cas_value_strong<mode> (operands[1], operands[2],
						operands[3], operands[4],
						operands[6], operands[7]));

  rtx val = gen_reg_rtx (SImode);
  if (operands[1] != const0_rtx)
    emit_move_insn (val, gen_rtx_SIGN_EXTEND (SImode, operands[1]));
  else
    emit_move_insn (val, const0_rtx);

  rtx exp = gen_reg_rtx (SImode);
  if (operands[3] != const0_rtx)
    emit_move_insn (exp, gen_rtx_SIGN_EXTEND (SImode, operands[3]));
  else
    emit_move_insn (exp, const0_rtx);

  rtx compare = val;
  if (exp != const0_rtx)
    {
      rtx difference = gen_rtx_MINUS (SImode, val, exp);
      compare = gen_reg_rtx (SImode);
      emit_move_insn  (compare, difference);
    }

  if (word_mode != SImode)
    {
      rtx reg = gen_reg_rtx (word_mode);
      emit_move_insn (reg, gen_rtx_SIGN_EXTEND (word_mode, compare));
      compare = reg;
    }

  emit_move_insn (operands[0], gen_rtx_EQ (SImode, compare, const0_rtx));
  DONE;
})

(define_expand "atomic_cas_value_strong<mode>"
  [(match_operand:SHORT 0 "register_operand") ;; val output
   (match_operand:SHORT 1 "memory_operand")   ;; memory
   (match_operand:SHORT 2 "reg_or_0_operand") ;; expected value
   (match_operand:SHORT 3 "reg_or_0_operand") ;; desired value
   (match_operand:SI 4 "const_int_operand")   ;; mod_s
   (match_operand:SI 5 "const_int_operand")   ;; mod_f
   (match_scratch:SHORT 6)]
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
{
  /* We have no QImode/HImode atomics, so form a mask, then use
     subword_atomic_cas_strong<mode> to implement a LR/SC version of the
     operation. */

  /* Logic duplicated in gcc/libgcc/config/riscv/atomic.c for use when inlining
     is disabled */

  rtx old = gen_reg_rtx (SImode);
  rtx mem = operands[1];
  rtx aligned_mem = gen_reg_rtx (SImode);
  rtx shift = gen_reg_rtx (SImode);
  rtx mask = gen_reg_rtx (SImode);
  rtx not_mask = gen_reg_rtx (SImode);

  riscv_subword_address (mem, &aligned_mem, &shift, &mask, &not_mask);

  rtx o = operands[2];
  rtx n = operands[3];
  rtx shifted_o = gen_reg_rtx (SImode);
  rtx shifted_n = gen_reg_rtx (SImode);

  riscv_lshift_subword (<MODE>mode, o, shift, &shifted_o);
  riscv_lshift_subword (<MODE>mode, n, shift, &shifted_n);

  emit_move_insn (shifted_o, gen_rtx_AND (SImode, shifted_o, mask));
  emit_move_insn (shifted_n, gen_rtx_AND (SImode, shifted_n, mask));

  emit_insn (gen_subword_atomic_cas_strong (old, aligned_mem,
					    shifted_o, shifted_n,
					    mask, not_mask));

  emit_move_insn (old, gen_rtx_ASHIFTRT (SImode, old,
					 gen_lowpart (QImode, shift)));

  emit_move_insn (operands[0], gen_lowpart (<MODE>mode, old));

  DONE;
})

(define_insn "subword_atomic_cas_strong"
  [(set (match_operand:SI 0 "register_operand" "=&r")			   ;; old value at mem
	(match_operand:SI 1 "memory_operand" "+A"))			   ;; mem location
   (set (match_dup 1)
	(unspec_volatile:SI [(match_operand:SI 2 "reg_or_0_operand" "rJ")  ;; expected value
			     (match_operand:SI 3 "reg_or_0_operand" "rJ")] ;; desired value
	 UNSPEC_COMPARE_AND_SWAP_SUBWORD))
	(match_operand:SI 4 "register_operand" "rI")			   ;; mask
	(match_operand:SI 5 "register_operand" "rI")			   ;; not_mask
	(clobber (match_scratch:SI 6 "=&r"))]				   ;; tmp_1
  "TARGET_ATOMIC && TARGET_INLINE_SUBWORD_ATOMIC"
  {
    return "1:\;"
	   "lr.w.aq\t%0, %1\;"
	   "and\t%6, %0, %4\;"
	   "bne\t%6, %z2, 1f\;"
	   "and\t%6, %0, %5\;"
	   "or\t%6, %6, %3\;"
	   "sc.w.rl\t%6, %6, %1\;"
	   "bnez\t%6, 1b\;"
	   "1:";
  }
  [(set (attr "length") (const_int 28))])

(define_expand "atomic_test_and_set"
  [(match_operand:QI 0 "register_operand" "")     ;; bool output
   (match_operand:QI 1 "riscv_sync_memory_operand" "+A")    ;; memory
   (match_operand:SI 2 "const_int_operand" "")]   ;; model
  "TARGET_ATOMIC"
{
  /* We have no QImode atomics, so use the address LSBs to form a mask,
     then use an aligned SImode atomic. */
  rtx result = operands[0];
  rtx mem = operands[1];
  rtx model = operands[2];
  rtx addr = force_reg (Pmode, XEXP (mem, 0));

  rtx aligned_addr = gen_reg_rtx (Pmode);
  emit_move_insn (aligned_addr, gen_rtx_AND (Pmode, addr, GEN_INT (-4)));

  rtx aligned_mem = change_address (mem, SImode, aligned_addr);
  set_mem_alias_set (aligned_mem, 0);

  rtx offset = gen_reg_rtx (SImode);
  emit_move_insn (offset, gen_rtx_AND (SImode, gen_lowpart (SImode, addr),
				       GEN_INT (3)));

  rtx tmp = gen_reg_rtx (SImode);
  emit_move_insn (tmp, GEN_INT (1));

  rtx shmt = gen_reg_rtx (SImode);
  emit_move_insn (shmt, gen_rtx_ASHIFT (SImode, offset, GEN_INT (3)));

  rtx word = gen_reg_rtx (SImode);
  emit_move_insn (word, gen_rtx_ASHIFT (SImode, tmp,
					gen_lowpart (QImode, shmt)));

  tmp = gen_reg_rtx (SImode);
  emit_insn (gen_atomic_fetch_orsi (tmp, aligned_mem, word, model));

  emit_move_insn (gen_lowpart (SImode, result),
		  gen_rtx_LSHIFTRT (SImode, tmp,
				    gen_lowpart (QImode, shmt)));
  DONE;
})
