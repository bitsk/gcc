
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_umar64(uint64_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__umar64 (t, a, b);
}

/* { dg-final { scan-assembler "\tumar64" } }*/

/* { dg-final { cleanup-saved-temps } } */
