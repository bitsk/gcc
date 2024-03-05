
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int16x2_t test_v_sunpkd830(int8x4_t a) {
    return __rv__v_sunpkd830 (a);
}

/* { dg-final { scan-assembler "\tsunpkd830" } }*/

/* { dg-final { cleanup-saved-temps } } */
