
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_pkbt32(uint64_t a, uint64_t b) {
    return __rv__pkbt32 (a, b);
}

/* { dg-final { scan-assembler "\tpkbt32" } }*/

/* { dg-final { cleanup-saved-temps } } */
