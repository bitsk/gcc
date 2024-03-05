/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, aadd)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, aaddu)
RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, asub)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, asubu)

/* { dg-final { scan-assembler-times "vaadd.vv" 30 } } */
/* { dg-final { scan-assembler-times "vaadd.vx" 36 } } */
/* { dg-final { scan-assembler-times "vaaddu.vv" 30 } } */
/* { dg-final { scan-assembler-times "vaaddu.vx" 36 } } */
/* { dg-final { scan-assembler-times "vasub.vv" 30 } } */
/* { dg-final { scan-assembler-times "vasub.vx" 36 } } */
/* { dg-final { scan-assembler-times "vasubu.vv" 30 } } */
/* { dg-final { scan-assembler-times "vasubu.vx" 36 } } */
