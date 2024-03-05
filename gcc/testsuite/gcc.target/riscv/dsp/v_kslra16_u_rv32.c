
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_kslra16_u(int16x2_t a, int32_t b) {
    return __rv__v_kslra16_u (a, b);
}

/* { dg-final { scan-assembler "\tkslra16.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
