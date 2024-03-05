
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_srl8_u(uintXLEN_t a, const uint32_t b) {
    return __rv__srl8_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrli8.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
