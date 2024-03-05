
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clrs16(uintXLEN_t a) {
    return __rv__clrs16 (a);
}

/* { dg-final { scan-assembler "\tclrs16" } }*/

/* { dg-final { cleanup-saved-temps } } */
