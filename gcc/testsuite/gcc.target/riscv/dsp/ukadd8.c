
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ukadd8(uintXLEN_t a, uintXLEN_t b) {
    return __rv__ukadd8 (a, b);
}

/* { dg-final { scan-assembler "\tukadd8" } }*/

/* { dg-final { cleanup-saved-temps } } */
