
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_sra32(int32x2_t a, uint32_t b) {
    return __rv__v_sra32 (a, b);
}

/* { dg-final { scan-assembler "\tsra32" } }*/

/* { dg-final { cleanup-saved-temps } } */
