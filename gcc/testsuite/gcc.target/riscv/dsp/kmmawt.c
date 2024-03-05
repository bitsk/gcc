
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmawt(intXLEN_t t, intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmawt (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawt" } }*/

/* { dg-final { cleanup-saved-temps } } */
