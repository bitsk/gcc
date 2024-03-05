
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smmwt_u(intXLEN_t a, uintXLEN_t b) {
    return __rv__smmwt_u (a, b);
}

/* { dg-final { scan-assembler "\tsmmwt.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
