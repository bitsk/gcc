
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clz8(uintXLEN_t a) {
    return __rv__clz8 (a);
}

/* { dg-final { scan-assembler "\tclz8" } }*/

/* { dg-final { cleanup-saved-temps } } */
