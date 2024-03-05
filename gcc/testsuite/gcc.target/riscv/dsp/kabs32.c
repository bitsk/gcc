
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_kabs32(uint64_t a) {
    return __rv__kabs32 (a);
}

/* { dg-final { scan-assembler "\tkabs32" } }*/

/* { dg-final { cleanup-saved-temps } } */
