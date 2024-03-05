
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_srl16_u(uintXLEN_t a, const uint32_t b) {
    return __rv__srl16_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrli16.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
