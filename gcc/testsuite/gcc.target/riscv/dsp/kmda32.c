
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kmda32(uint64_t a, uint64_t b) {
    return __rv__kmda32 (a, b);
}

/* { dg-final { scan-assembler "\tkmda32" } }*/

/* { dg-final { cleanup-saved-temps } } */
