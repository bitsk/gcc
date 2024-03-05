
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_umul8(uint8x4_t a, uint8x4_t b) {
    return __rv__v_umul8 (a, b);
}

/* { dg-final { scan-assembler "\tumul8" } }*/

/* { dg-final { cleanup-saved-temps } } */
