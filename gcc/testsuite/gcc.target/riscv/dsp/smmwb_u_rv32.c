
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smmwb_u(intXLEN_t a, uintXLEN_t b) {
    return __rv__smmwb_u (a, b);
}

/* { dg-final { scan-assembler "\tsmmwb.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
