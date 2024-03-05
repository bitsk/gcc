
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t test_v_sra8_u(int8x4_t a, const uint32_t b) {
    return __rv__v_sra8_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrai8.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
