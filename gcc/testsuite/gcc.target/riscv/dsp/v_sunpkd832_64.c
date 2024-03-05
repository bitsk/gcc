
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_sunpkd832(int8x8_t a) {
    return __rv__v_sunpkd832 (a);
}

/* { dg-final { scan-assembler "\tsunpkd832" } }*/

/* { dg-final { cleanup-saved-temps } } */
