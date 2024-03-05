
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kaddw(int32_t a, int32_t b) {
    return __rv__kaddw (a, b);
}

/* { dg-final { scan-assembler "\tkaddw" } }*/

/* { dg-final { cleanup-saved-temps } } */
