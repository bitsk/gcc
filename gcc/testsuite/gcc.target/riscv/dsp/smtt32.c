
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smtt32(uint64_t a, uint64_t b) {
    return __rv__smtt32 (a, b);
}

/* { dg-final { scan-assembler "\tsmtt32" } }*/

/* { dg-final { cleanup-saved-temps } } */
