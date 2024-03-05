
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_rdov(void) {
    return __rv__rdov ();
}

/* { dg-final { scan-assembler "\trdov" } }*/

/* { dg-final { cleanup-saved-temps } } */
