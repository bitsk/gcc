
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kadd8(uintXLEN_t a, uintXLEN_t b) {
    return __rv__kadd8 (a, b);
}

/* { dg-final { scan-assembler "\tkadd8" } }*/

/* { dg-final { cleanup-saved-temps } } */
