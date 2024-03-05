
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_swap16(uint16x4_t a) {
    return __rv__v_swap16 (a);
}

/* { dg-final { scan-assembler "\tswap16" } }*/

/* { dg-final { cleanup-saved-temps } } */
