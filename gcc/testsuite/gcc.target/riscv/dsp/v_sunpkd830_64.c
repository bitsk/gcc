
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x4_t test_v_sunpkd830(int8x8_t a) {
    return __rv__v_sunpkd830 (a);
}

/* { dg-final { scan-assembler "\tsunpkd830" } }*/

/* { dg-final { cleanup-saved-temps } } */
