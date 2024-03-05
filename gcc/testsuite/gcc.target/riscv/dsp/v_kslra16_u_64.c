
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_kslra16_u(int16x4_t a, int32_t b) {
    return __rv__v_kslra16_u (a, b);
}

/* { dg-final { scan-assembler "\tkslra16.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
