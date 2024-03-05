
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_radd8(uintXLEN_t a, uintXLEN_t b) {
    return __rv__radd8 (a, b);
}

/* { dg-final { scan-assembler "\tradd8" } }*/

/* { dg-final { cleanup-saved-temps } } */
