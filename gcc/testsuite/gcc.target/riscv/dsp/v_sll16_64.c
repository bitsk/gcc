
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_sll16(uint16x4_t a, uint32_t b) {
    return __rv__v_sll16 (a, b);
}

/* { dg-final { scan-assembler "\tsll16" } }*/

/* { dg-final { cleanup-saved-temps } } */
