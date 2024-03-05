/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_MASKED_TEST, min)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_MASKED_TEST, minu)
RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_MASKED_TEST, max)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_MASKED_TEST, maxu)

/* { dg-final { scan-assembler-times "vmin.vv" 26 } } */
/* { dg-final { scan-assembler-times "vmin.vx" 18 } } */
/* { dg-final { scan-assembler-times "vmax.vv" 26 } } */
/* { dg-final { scan-assembler-times "vmax.vx" 18 } } */
/* { dg-final { scan-assembler-times "vminu.vv" 26 } } */
/* { dg-final { scan-assembler-times "vminu.vx" 18 } } */
/* { dg-final { scan-assembler-times "vmaxu.vv" 26 } } */
/* { dg-final { scan-assembler-times "vmaxu.vx" 18 } } */
