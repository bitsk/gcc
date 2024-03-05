/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, or)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, or)

/* { dg-final { scan-assembler-times "vor.vv" 60 } } */
/* { dg-final { scan-assembler-times "vor.vx" 36 } } */
/* { dg-final { scan-assembler-times "vor.vi" 36 } } */
