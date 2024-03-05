
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_zunpkd820(uintXLEN_t a) {
    return __rv__zunpkd820 (a);
}

/* { dg-final { scan-assembler "\tzunpkd820" } }*/

/* { dg-final { cleanup-saved-temps } } */
