
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t test_v_sclip8(int8x4_t a, const uint32_t b) {
    return __rv__v_sclip8 (a, 1);
}

/* { dg-final { scan-assembler "\tsclip8" } }*/

/* { dg-final { cleanup-saved-temps } } */
