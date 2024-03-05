
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_sstas16(int16x2_t a, int16x2_t b) {
    return __rv__v_sstas16 (a, b);
}

/* { dg-final { scan-assembler "\tstas16" } }*/

/* { dg-final { cleanup-saved-temps } } */
