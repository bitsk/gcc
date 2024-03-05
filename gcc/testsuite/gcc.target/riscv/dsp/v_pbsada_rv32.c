
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint32_t test_v_pbsada(uint32_t t, uint8x4_t a, uint8x4_t b) {
    return __rv__v_pbsada (t, a, b);
}

/* { dg-final { scan-assembler "\tpbsada" } }*/

/* { dg-final { cleanup-saved-temps } } */
