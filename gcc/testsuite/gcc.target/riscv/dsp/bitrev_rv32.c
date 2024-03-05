
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_bitrev(uintXLEN_t a, uint32_t msb) {
    return __rv__bitrev (a, msb);
}

/* { dg-final { scan-assembler "\tbitrev" } }*/

/* { dg-final { cleanup-saved-temps } } */
