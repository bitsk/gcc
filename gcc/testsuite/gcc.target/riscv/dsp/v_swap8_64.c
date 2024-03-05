
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x8_t test_v_swap8(uint8x8_t a) {
    return __rv__v_swap8 (a);
}

/* { dg-final { scan-assembler "\tswap8" } }*/

/* { dg-final { cleanup-saved-temps } } */
