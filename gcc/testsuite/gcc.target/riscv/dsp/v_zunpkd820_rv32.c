
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x2_t test_v_zunpkd820(uint8x4_t a) {
    return __rv__v_zunpkd820 (a);
}

/* { dg-final { scan-assembler "\tzunpkd820" } }*/

/* { dg-final { cleanup-saved-temps } } */
