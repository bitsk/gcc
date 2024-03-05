
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kcrsa16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__kcrsa16 (a, b);
}

/* { dg-final { scan-assembler "\tkcrsa16" } }*/

/* { dg-final { cleanup-saved-temps } } */
