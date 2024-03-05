
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_kslra32(uint64_t a, int32_t b) {
    return __rv__kslra32 (a, b);
}

/* { dg-final { scan-assembler "\tkslra32" } }*/

/* { dg-final { cleanup-saved-temps } } */
