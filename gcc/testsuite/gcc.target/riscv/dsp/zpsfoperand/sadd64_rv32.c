
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_sadd64(int64_t a, int64_t b) {
    return __rv__sadd64 (a, b);
}

/* { dg-final { scan-assembler "\tadd64" } }*/

/* { dg-final { cleanup-saved-temps } } */
