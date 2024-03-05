/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

#define RVV_TEST_SLIDE1UPDOWN(STYPE, VCLASST, VCLASS, EM, MLEN, STYPEC, SEW, PREFIX)	\
  void test_slide1up_sx##VCLASS##EM (STYPE *x, STYPE *y, STYPE s, word_type vl) {	\
    v##VCLASST##EM##_t vx, vy;					\
    vbool##MLEN##_t mask;						\
    mask = MSET (MLEN);					\
    vx = VLOAD(VCLASS, SEW, EM, x);					\
    vy = VLOAD(VCLASS, SEW, EM, y);					\
    vx = v##PREFIX##slide1up_v##STYPEC##_##VCLASS##EM##_m(mask, vy, vx, s, vl);		\
    VSTORE(VCLASS, SEW, EM, x, vx);						\
  }									\
  void test_slide1down_sx##VCLASS##EM (STYPE *x, STYPE *y, STYPE s, word_type vl) {	\
    v##VCLASST##EM##_t vx, vy;					\
    vbool##MLEN##_t mask;						\
    mask = MSET (MLEN);					\
    vx = VLOAD(VCLASS, SEW, EM, x);					\
    vy = VLOAD(VCLASS, SEW, EM, y);					\
    vx = v##PREFIX##slide1down_v##STYPEC##_##VCLASS##EM##_m(mask, vy, vx, s, vl);	\
    VSTORE(VCLASS, SEW, EM, x, vx);						\
  }

RVV_INT_TEST_ARG (RVV_TEST_SLIDE1UPDOWN, )
RVV_UINT_TEST_ARG (RVV_TEST_SLIDE1UPDOWN, )

/* { dg-final { scan-assembler-times "vslide1up.vx" 52 } } */
/* { dg-final { scan-assembler-times "vslide1down.vx" 52 } } */
