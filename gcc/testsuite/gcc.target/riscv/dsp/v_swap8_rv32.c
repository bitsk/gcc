
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_swap8(uint8x4_t a) {
    return __rv__v_swap8 (a);
}

/* { dg-final { scan-assembler "\tswap8" } }*/

/* { dg-final { cleanup-saved-temps } } */
