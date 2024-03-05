
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_uadd64(uint64_t a, uint64_t b) {
    return __rv__uadd64 (a, b);
}

/* { dg-final { scan-assembler "\tadd64" } }*/

/* { dg-final { cleanup-saved-temps } } */
