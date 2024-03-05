
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_bitrev(uintXLEN_t a, const uint32_t msb) {
    return __rv__bitrev (a, 1);
}

/* { dg-final { scan-assembler "\tbitrevi" } }*/

/* { dg-final { cleanup-saved-temps } } */
