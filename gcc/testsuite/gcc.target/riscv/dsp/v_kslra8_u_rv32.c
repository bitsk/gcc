
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t test_v_kslra8_u(int8x4_t a, int32_t b) {
    return __rv__v_kslra8_u (a, b);
}

/* { dg-final { scan-assembler "\tkslra8.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
