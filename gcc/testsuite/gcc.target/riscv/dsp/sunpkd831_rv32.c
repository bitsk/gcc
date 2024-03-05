
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sunpkd831(uintXLEN_t a) {
    return __rv__sunpkd831 (a);
}

/* { dg-final { scan-assembler "\tsunpkd831" } }*/

/* { dg-final { cleanup-saved-temps } } */
