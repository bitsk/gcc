
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_pbsad(uintXLEN_t a, uintXLEN_t b) {
    return __rv__pbsad (a, b);
}

/* { dg-final { scan-assembler "\tpbsad" } }*/

/* { dg-final { cleanup-saved-temps } } */
