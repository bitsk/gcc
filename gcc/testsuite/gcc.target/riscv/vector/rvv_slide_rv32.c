/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

#define RVV_TEST_SLIDE1UPDOWN(STYPE, VCLASST, VCLASS, EM, MLEN, STYPEC, SEW, PREFIX)	\
  void test_slide1up_sx##VCLASS##EM (STYPE *x, STYPE s, word_type vl) {	\
    v##VCLASST##EM##_t vx;					\
    vx = VLOAD(VCLASS, SEW, EM, x);				\
    vx = v##PREFIX##slide1up_v##STYPEC##_##VCLASS##EM(vx, s, vl);		\
    VSTORE(VCLASS, SEW, EM, x, vx);					\
  }								\
  void test_slide1down_sx##VCLASS##EM (STYPE *x, STYPE s, word_type vl) {	\
    v##VCLASST##EM##_t vx;					\
    vx = VLOAD(VCLASS, SEW, EM, x);				\
    vx = v##PREFIX##slide1down_v##STYPEC##_##VCLASS##EM(vx, s, vl);		\
    VSTORE(VCLASS, SEW, EM, x, vx);					\
  }

RVV_INT_TEST_ARG (RVV_TEST_SLIDE1UPDOWN, )
RVV_UINT_TEST_ARG (RVV_TEST_SLIDE1UPDOWN, )


/* { dg-final { scan-assembler-times "vslide1up.vx" 52 } } */
/* { dg-final { scan-assembler-times "vslide1down.vx" 52 } } */
