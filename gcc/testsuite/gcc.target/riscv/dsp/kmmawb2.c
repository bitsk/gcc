
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmawb2(intXLEN_t t, intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmawb2 (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawb2" } }*/

/* { dg-final { cleanup-saved-temps } } */
