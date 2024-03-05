
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_srl32_u(uint64_t a, uint32_t b) {
    return __rv__srl32_u (a, b);
}

/* { dg-final { scan-assembler "\tsrl32.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
