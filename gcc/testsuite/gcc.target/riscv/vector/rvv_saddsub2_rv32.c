/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, sadd)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, saddu)
RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, ssub)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, ssubu)

/* { dg-final { scan-assembler-times "vsadd.vv" 30 } } */
/* { dg-final { scan-assembler-times "vsadd.vx" 18 } } */
/* { dg-final { scan-assembler-times "vsadd.vi" 18 } } */
/* { dg-final { scan-assembler-times "vsaddu.vv" 30 } } */
/* { dg-final { scan-assembler-times "vsaddu.vx" 18 } } */
/* { dg-final { scan-assembler-times "vsaddu.vi" 18 } } */
/* { dg-final { scan-assembler-times "vssub.vv" 30 } } */
/* { dg-final { scan-assembler-times "vssub.vx" 36 } } */
/* { dg-final { scan-assembler-times "vssubu.vv" 30 } } */
/* { dg-final { scan-assembler-times "vssubu.vx" 36 } } */
