
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_ksubw(int32_t a, int32_t b) {
    return __rv__ksubw (a, b);
}

/* { dg-final { scan-assembler "\tksubw" } }*/

/* { dg-final { cleanup-saved-temps } } */
