
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_smulx8(int8x4_t a, int8x4_t b) {
    return __rv__v_smulx8 (a, b);
}

/* { dg-final { scan-assembler "\tsmulx8" } }*/

/* { dg-final { cleanup-saved-temps } } */
