
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_ksub32(int32x2_t a, int32x2_t b) {
    return __rv__v_ksub32 (a, b);
}

/* { dg-final { scan-assembler "\tksub32" } }*/

/* { dg-final { cleanup-saved-temps } } */
