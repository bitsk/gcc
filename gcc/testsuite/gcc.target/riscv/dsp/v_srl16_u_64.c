
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_srl16_u(uint16x4_t a, uint32_t b) {
    return __rv__v_srl16_u (a, b);
}

/* { dg-final { scan-assembler "\tsrl16.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
