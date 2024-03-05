
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smalxda(int64_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__smalxda (t, a, b);
}

/* { dg-final { scan-assembler "\tsmalxda" } }*/

/* { dg-final { cleanup-saved-temps } } */
