
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_pbsada(uintXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__pbsada (t, a, b);
}

/* { dg-final { scan-assembler "\tpbsada" } }*/

/* { dg-final { cleanup-saved-temps } } */
