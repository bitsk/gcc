
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ukcrsa16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__ukcrsa16 (a, b);
}

/* { dg-final { scan-assembler "\tukcrsa16" } }*/

/* { dg-final { cleanup-saved-temps } } */
