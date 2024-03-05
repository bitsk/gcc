
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smaldrs(int64_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__smaldrs (t, a, b);
}

/* { dg-final { scan-assembler "\tsmaldrs" } }*/

/* { dg-final { cleanup-saved-temps } } */
