
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_umin8(uint8x4_t a, uint8x4_t b) {
    return __rv__v_umin8 (a, b);
}

/* { dg-final { scan-assembler "\tumin8" } }*/

/* { dg-final { cleanup-saved-temps } } */
