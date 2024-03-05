
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_sra_u(intXLEN_t a, uint32_t b) {
    return __rv__sra_u (a, b);
}

/* { dg-final { scan-assembler "\tsra.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
