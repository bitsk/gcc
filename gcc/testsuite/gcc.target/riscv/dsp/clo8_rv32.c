
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clo8(uintXLEN_t a) {
    return __rv__clo8 (a);
}

/* { dg-final { scan-assembler "\tclo8" } }*/

/* { dg-final { cleanup-saved-temps } } */
