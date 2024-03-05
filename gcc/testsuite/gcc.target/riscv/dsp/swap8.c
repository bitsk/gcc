
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_swap8(uintXLEN_t a) {
    return __rv__swap8 (a);
}

/* { dg-final { scan-assembler "\tswap8" } }*/

/* { dg-final { cleanup-saved-temps } } */
