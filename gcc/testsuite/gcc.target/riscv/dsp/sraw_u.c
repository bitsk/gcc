
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_sraw_u(int32_t a, const uint32_t b) {
    return __rv__sraw_u (a, 1);
}

/* { dg-final { scan-assembler "\tsraiw.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
