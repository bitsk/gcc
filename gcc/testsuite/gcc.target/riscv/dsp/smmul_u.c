
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smmul_u(intXLEN_t a, intXLEN_t b) {
    return __rv__smmul_u (a, b);
}

/* { dg-final { scan-assembler "\tsmmul.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
