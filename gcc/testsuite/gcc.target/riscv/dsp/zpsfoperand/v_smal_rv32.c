
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_v_smal(int64_t a, int16x2_t b) {
    return __rv__v_smal (a, b);
}

/* { dg-final { scan-assembler "\tsmal" } }*/

/* { dg-final { cleanup-saved-temps } } */
