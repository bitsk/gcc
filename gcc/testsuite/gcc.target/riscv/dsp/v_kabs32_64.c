
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_kabs32(int32x2_t a) {
    return __rv__v_kabs32 (a);
}

/* { dg-final { scan-assembler "\tkabs32" } }*/

/* { dg-final { cleanup-saved-temps } } */
