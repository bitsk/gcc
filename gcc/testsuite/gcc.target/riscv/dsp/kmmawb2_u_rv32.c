
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmawb2_u(intXLEN_t t, intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmawb2_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmawb2.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
