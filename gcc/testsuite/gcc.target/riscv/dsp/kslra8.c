
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kslra8(uintXLEN_t a, int32_t b) {
    return __rv__kslra8 (a, b);
}

/* { dg-final { scan-assembler "\tkslra8" } }*/

/* { dg-final { cleanup-saved-temps } } */
