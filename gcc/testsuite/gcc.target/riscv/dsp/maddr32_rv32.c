
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_maddr32(int32_t t, int32_t a, int32_t b) {
    return __rv__maddr32 (t, a, b);
}

/* { dg-final { scan-assembler "\tmaddr32" } }*/

/* { dg-final { cleanup-saved-temps } } */
