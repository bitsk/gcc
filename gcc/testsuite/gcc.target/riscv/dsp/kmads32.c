
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kmads32(int64_t t, uint64_t a, uint64_t b) {
    return __rv__kmads32 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmads32" } }*/

/* { dg-final { cleanup-saved-temps } } */
