
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ukaddw(uint32_t a, uint32_t b) {
    return __rv__ukaddw (a, b);
}

/* { dg-final { scan-assembler "\tukaddw" } }*/

/* { dg-final { cleanup-saved-temps } } */
