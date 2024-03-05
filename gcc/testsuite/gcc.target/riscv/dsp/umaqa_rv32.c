
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_umaqa(uintXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__umaqa (t, a, b);
}

/* { dg-final { scan-assembler "\tumaqa" } }*/

/* { dg-final { cleanup-saved-temps } } */
