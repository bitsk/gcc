
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_bpick(uintXLEN_t a, uintXLEN_t b, uintXLEN_t c) {
    return __rv__bpick (a, b, c);
}

/* { dg-final { scan-assembler "\tbpick" } }*/

/* { dg-final { cleanup-saved-temps } } */
