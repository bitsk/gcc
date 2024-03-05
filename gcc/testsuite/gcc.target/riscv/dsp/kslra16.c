
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kslra16(uintXLEN_t a, int32_t b) {
    return __rv__kslra16 (a, b);
}

/* { dg-final { scan-assembler "\tkslra16" } }*/

/* { dg-final { cleanup-saved-temps } } */
