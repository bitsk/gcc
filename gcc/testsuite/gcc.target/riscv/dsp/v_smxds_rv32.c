
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_smxds(int16x2_t a, int16x2_t b) {
    return __rv__v_smxds (a, b);
}

/* { dg-final { scan-assembler "\tsmxds" } }*/

/* { dg-final { cleanup-saved-temps } } */
