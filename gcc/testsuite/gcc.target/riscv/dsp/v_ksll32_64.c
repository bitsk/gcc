
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_ksll32(int32x2_t a, uint32_t b) {
    return __rv__v_ksll32 (a, b);
}

/* { dg-final { scan-assembler "\tksll32" } }*/

/* { dg-final { cleanup-saved-temps } } */
