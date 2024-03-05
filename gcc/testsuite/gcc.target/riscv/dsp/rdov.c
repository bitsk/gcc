
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_rdov(void) {
    return __rv__rdov ();
}

/* { dg-final { scan-assembler "\trdov" } }*/

/* { dg-final { cleanup-saved-temps } } */
