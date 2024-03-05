
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_kmmsb(int32x2_t t, int32x2_t a, int32x2_t b) {
    return __rv__v_kmmsb (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmsb" } }*/

/* { dg-final { cleanup-saved-temps } } */
