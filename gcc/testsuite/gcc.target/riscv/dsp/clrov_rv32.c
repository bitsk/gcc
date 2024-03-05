
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

void test_clrov(void) {
    return __rv__clrov ();
}

/* { dg-final { scan-assembler "\tclrov" } }*/

/* { dg-final { cleanup-saved-temps } } */
