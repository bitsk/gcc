
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_kcras32(uint64_t a, uint64_t b) {
    return __rv__kcras32 (a, b);
}

/* { dg-final { scan-assembler "\tkcras32" } }*/

/* { dg-final { cleanup-saved-temps } } */
