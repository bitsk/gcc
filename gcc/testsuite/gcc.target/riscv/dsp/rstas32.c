
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_rstas32(uint64_t a, uint64_t b) {
    return __rv__rstas32 (a, b);
}

/* { dg-final { scan-assembler "\trstas32" } }*/

/* { dg-final { cleanup-saved-temps } } */
