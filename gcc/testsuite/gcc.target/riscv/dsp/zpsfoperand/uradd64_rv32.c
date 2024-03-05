
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_uradd64(uint64_t a, uint64_t b) {
    return __rv__uradd64 (a, b);
}

/* { dg-final { scan-assembler "\turadd64" } }*/

/* { dg-final { cleanup-saved-temps } } */
