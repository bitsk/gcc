
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_sclip32(intXLEN_t a, const uint32_t b) {
    return __rv__sclip32 (a, 1);
}

/* { dg-final { scan-assembler "\tsclip32" } }*/

/* { dg-final { cleanup-saved-temps } } */
