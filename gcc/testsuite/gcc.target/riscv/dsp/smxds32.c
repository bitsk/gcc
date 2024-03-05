
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_smxds32(uint64_t a, uint64_t b) {
    return __rv__smxds32 (a, b);
}

/* { dg-final { scan-assembler "\tsmxds32" } }*/

/* { dg-final { cleanup-saved-temps } } */
