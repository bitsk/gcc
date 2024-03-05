
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_zunpkd810(uintXLEN_t a) {
    return __rv__zunpkd810 (a);
}

/* { dg-final { scan-assembler "\tzunpkd810" } }*/

/* { dg-final { cleanup-saved-temps } } */
