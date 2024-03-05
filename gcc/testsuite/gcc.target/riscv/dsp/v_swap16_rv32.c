
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x2_t test_v_swap16(uint16x2_t a) {
    return __rv__v_swap16 (a);
}

/* { dg-final { scan-assembler "\tswap16" } }*/

/* { dg-final { cleanup-saved-temps } } */
