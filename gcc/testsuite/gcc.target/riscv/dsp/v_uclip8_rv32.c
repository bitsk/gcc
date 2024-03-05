
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_uclip8(int8x4_t a, const uint32_t b) {
    return __rv__v_uclip8 (a, 1);
}

/* { dg-final { scan-assembler "\tuclip8" } }*/

/* { dg-final { cleanup-saved-temps } } */
