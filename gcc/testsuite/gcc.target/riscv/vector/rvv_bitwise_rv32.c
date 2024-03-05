/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_TEST, xor)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_TEST, xor)
RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_TEST, and)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_TEST, and)
RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_TEST, or)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_TEST, or)

/* { dg-final { scan-assembler-times "vxor.vv" 60 } } */
/* { dg-final { scan-assembler-times "vxor.vx" 36 } } */
/* { dg-final { scan-assembler-times "vxor.vi" 36 } } */
/* { dg-final { scan-assembler-times "vand.vv" 60 } } */
/* { dg-final { scan-assembler-times "vand.vx" 36 } } */
/* { dg-final { scan-assembler-times "vand.vi" 36 } } */
/* { dg-final { scan-assembler-times "vor.vv" 60 } } */
/* { dg-final { scan-assembler-times "vor.vx" 36 } } */
/* { dg-final { scan-assembler-times "vor.vi" 36 } } */
