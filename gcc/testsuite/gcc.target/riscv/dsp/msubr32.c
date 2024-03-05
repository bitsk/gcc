
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_msubr32(int32_t t, int32_t a, int32_t b) {
    return __rv__msubr32 (t, a, b);
}

/* { dg-final { scan-assembler "\tmsubr32" } }*/

/* { dg-final { cleanup-saved-temps } } */
