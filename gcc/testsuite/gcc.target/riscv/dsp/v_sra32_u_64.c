
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_sra32_u(int32x2_t a, uint32_t b) {
    return __rv__v_sra32_u (a, b);
}

/* { dg-final { scan-assembler "\tsra32.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
