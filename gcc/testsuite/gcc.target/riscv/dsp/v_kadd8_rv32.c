
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t test_v_kadd8(int8x4_t a, int8x4_t b) {
    return __rv__v_kadd8 (a, b);
}

/* { dg-final { scan-assembler "\tkadd8" } }*/

/* { dg-final { cleanup-saved-temps } } */
