
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmac_u(intXLEN_t t, intXLEN_t a, intXLEN_t b) {
    return __rv__kmmac_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmac.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
