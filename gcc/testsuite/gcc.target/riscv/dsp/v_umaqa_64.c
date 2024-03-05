
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint32x2_t test_v_umaqa(uint32x2_t t, uint8x8_t a, uint8x8_t b) {
    return __rv__v_umaqa (t, a, b);
}

/* { dg-final { scan-assembler "\tumaqa" } }*/

/* { dg-final { cleanup-saved-temps } } */
