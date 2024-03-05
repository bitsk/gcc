
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_v_kdmabt(int32_t t, int16x2_t a, int16x2_t b) {
    return __rv__v_kdmabt (t, a, b);
}

/* { dg-final { scan-assembler "\tkdmabt" } }*/

/* { dg-final { cleanup-saved-temps } } */
