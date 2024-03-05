
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_sra16(int16x2_t a, const uint32_t b) {
    return __rv__v_sra16 (a, 1);
}

/* { dg-final { scan-assembler "\tsrai16" } }*/

/* { dg-final { cleanup-saved-temps } } */
