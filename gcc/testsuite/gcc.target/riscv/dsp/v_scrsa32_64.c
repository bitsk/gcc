
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_scrsa32(int32x2_t a, int32x2_t b) {
    return __rv__v_scrsa32 (a, b);
}

/* { dg-final { scan-assembler "\tcrsa32" } }*/

/* { dg-final { cleanup-saved-temps } } */
