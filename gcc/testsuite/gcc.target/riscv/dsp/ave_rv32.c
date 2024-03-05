
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_ave(intXLEN_t a, intXLEN_t b) {
    return __rv__ave (a, b);
}

/* { dg-final { scan-assembler "\tave" } }*/

/* { dg-final { cleanup-saved-temps } } */
