
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_swap16(uintXLEN_t a) {
    return __rv__swap16 (a);
}

/* { dg-final { scan-assembler "\tswap16" } }*/

/* { dg-final { cleanup-saved-temps } } */
