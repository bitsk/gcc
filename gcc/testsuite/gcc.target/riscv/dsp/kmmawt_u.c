
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmawt_u(intXLEN_t t, intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmawt_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawt.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
