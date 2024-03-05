
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sra16(uintXLEN_t a, uint32_t b) {
    return __rv__sra16 (a, b);
}

/* { dg-final { scan-assembler "\tsra16" } }*/

/* { dg-final { cleanup-saved-temps } } */
