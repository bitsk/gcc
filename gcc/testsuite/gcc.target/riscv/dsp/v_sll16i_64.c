
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_sll16(uint16x4_t a, const uint32_t b) {
    return __rv__v_sll16 (a, 1);
}

/* { dg-final { scan-assembler "\tslli16" } }*/

/* { dg-final { cleanup-saved-temps } } */
