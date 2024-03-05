
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_srl8(uintXLEN_t a, uint32_t b) {
    return __rv__srl8 (a, b);
}

/* { dg-final { scan-assembler "\tsrl8" } }*/

/* { dg-final { cleanup-saved-temps } } */
