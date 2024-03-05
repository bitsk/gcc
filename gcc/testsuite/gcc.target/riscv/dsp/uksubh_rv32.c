
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_uksubh(uint32_t a, uint32_t b) {
    return __rv__uksubh (a, b);
}

/* { dg-final { scan-assembler "\tuksubh" } }*/

/* { dg-final { cleanup-saved-temps } } */
