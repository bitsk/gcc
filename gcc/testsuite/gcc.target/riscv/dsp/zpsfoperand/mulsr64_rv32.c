
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_mulsr64(int32_t a, int32_t b) {
    return __rv__mulsr64 (a, b);
}

/* { dg-final { scan-assembler "\tmulsr64" } }*/

/* { dg-final { cleanup-saved-temps } } */
