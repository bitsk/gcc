
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sra16_u(uintXLEN_t a, uint32_t b) {
    return __rv__sra16_u (a, b);
}

/* { dg-final { scan-assembler "\tsra16.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
