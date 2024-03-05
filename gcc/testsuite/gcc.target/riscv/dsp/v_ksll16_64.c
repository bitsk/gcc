
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_ksll16(int16x4_t a, uint32_t b) {
    return __rv__v_ksll16 (a, b);
}

/* { dg-final { scan-assembler "\tksll16" } }*/

/* { dg-final { cleanup-saved-temps } } */
