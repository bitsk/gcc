
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_sra32(uint64_t a, uint32_t b) {
    return __rv__sra32 (a, b);
}

/* { dg-final { scan-assembler "\tsra32" } }*/

/* { dg-final { cleanup-saved-temps } } */
