
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_ukcrsa32(uint64_t a, uint64_t b) {
    return __rv__ukcrsa32 (a, b);
}

/* { dg-final { scan-assembler "\tukcrsa32" } }*/

/* { dg-final { cleanup-saved-temps } } */
