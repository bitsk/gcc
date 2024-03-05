
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_kmmawt2_u(int32_t t, int32_t a, int16x2_t b) {
    return __rv__v_kmmawt2_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawt2.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
