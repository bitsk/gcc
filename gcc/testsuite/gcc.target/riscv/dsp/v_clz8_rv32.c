
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_clz8(uint8x4_t a) {
    return __rv__v_clz8 (a);
}

/* { dg-final { scan-assembler "\tclz8" } }*/

/* { dg-final { cleanup-saved-temps } } */
