/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

RVV_INT_TEST_ARG(RVV_UNARY_BUILTIN_VEC_MASKED_TEST, not)
RVV_UINT_TEST_ARG(RVV_UNARY_BUILTIN_VEC_MASKED_TEST, not)

/* { dg-final { scan-assembler-times "vnot.v" 44 } } */
