
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smslda(int64_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__smslda (t, a, b);
}

/* { dg-final { scan-assembler "\tsmslda" } }*/

/* { dg-final { cleanup-saved-temps } } */
