
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32x2_t test_v_smmul_u(int32x2_t a, int32x2_t b) {
    return __rv__v_smmul_u (a, b);
}

/* { dg-final { scan-assembler "\tsmmul.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
