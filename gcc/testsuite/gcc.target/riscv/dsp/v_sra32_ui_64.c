
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_sra32_u(int32x2_t a, const uint32_t b) {
    return __rv__v_sra32_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrai32.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
