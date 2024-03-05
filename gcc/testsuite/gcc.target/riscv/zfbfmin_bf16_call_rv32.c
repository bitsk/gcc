/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zfbfmin -mabi=ilp32d -O" } */


__bf16 add (__bf16 a, __bf16 b) __attribute__ ((noinline));
__bf16 add (__bf16 a, __bf16 b)
{
  return a + b;
}

__bf16 test(__bf16 a, __bf16 b)
{
  return add (a, b);
}

/* { dg-final { scan-assembler-times "fcvt.s.bf16" 2 } } */
/* { dg-final { scan-assembler-times "fcvt.bf16.s" 1 } } */
