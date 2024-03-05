
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_sunpkd820(int8x8_t a) {
    return __rv__v_sunpkd820 (a);
}

/* { dg-final { scan-assembler "\tsunpkd820" } }*/

/* { dg-final { cleanup-saved-temps } } */
