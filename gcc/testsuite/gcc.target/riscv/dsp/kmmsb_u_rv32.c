
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmsb_u(intXLEN_t t, intXLEN_t a, intXLEN_t b) {
    return __rv__kmmsb_u (t, a, b);
}

/* { dg-final { scan-assembler "\tkmmsb.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
