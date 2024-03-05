
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kmsr64(int64_t t, intXLEN_t a, intXLEN_t b) {
    return __rv__kmsr64 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmsr64" } }*/

/* { dg-final { cleanup-saved-temps } } */
