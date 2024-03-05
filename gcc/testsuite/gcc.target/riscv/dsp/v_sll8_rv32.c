
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_sll8(uint8x4_t a, uint32_t b) {
    return __rv__v_sll8 (a, b);
}

/* { dg-final { scan-assembler "\tsll8" } }*/

/* { dg-final { cleanup-saved-temps } } */
