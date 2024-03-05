/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d -O0" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

#define RVV_INT64_UINT64_TEST(MACRO)	\
  MACRO(int64_t, int, i, 64m1, 64, x, 64)	\
  MACRO(int64_t, int, i, 64m2, 32, x, 64)	\
  MACRO(int64_t, int, i, 64m4, 16, x, 64)	\
  MACRO(int64_t, int, i, 64m8,  8, x, 64) \
  MACRO(uint64_t, uint, u, 64m1, 64, x, 64)	\
  MACRO(uint64_t, uint, u, 64m2, 32, x, 64)	\
  MACRO(uint64_t, uint, u, 64m4, 16, x, 64)	\
  MACRO(uint64_t, uint, u, 64m8,  8, x, 64)

#define RVV_TEST_MV_SV_VS(STYPE, VCLASST, VCLASS, EM, MLEN, STYPEC, SEW)\
  STYPE test_mv_xs##VCLASS##EM (v##VCLASST##EM##_t vx) {			\
    STYPE y = vmv_x_s_##VCLASS##EM##_##VCLASS##SEW (vx);				\
    return y;			\
  } \
  v##VCLASST##EM##_t test_mv_sx##VCLASS##EM (STYPE *x, STYPE s, word_type vl) {		\
    v##VCLASST##EM##_t vx;					\
    vx = VLOAD(VCLASS, SEW, EM, x);				\
    return vmv_s_x_##VCLASS##EM(vx, s, vl);				\
  }

RVV_INT64_UINT64_TEST (RVV_TEST_MV_SV_VS)

/* { dg-final { scan-assembler-times "vmv.x.s" 16 } } */
/* { dg-final { scan-assembler-not "vmv.s.x"} } */
