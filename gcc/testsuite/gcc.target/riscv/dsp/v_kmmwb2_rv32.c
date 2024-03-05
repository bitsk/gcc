
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_kmmwb2(int32_t a, int16x2_t b) {
    return __rv__v_kmmwb2 (a, b);
}

/* { dg-final { scan-assembler "\tkmmwb2" } }*/

/* { dg-final { cleanup-saved-temps } } */
