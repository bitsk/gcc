
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp_zpsfoperand -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smal(int64_t a, uintXLEN_t b) {
    return __rv__smal (a, b);
}

/* { dg-final { scan-assembler "\tsmal" } }*/

/* { dg-final { cleanup-saved-temps } } */
