
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sll8(uintXLEN_t a, uint32_t b) {
    return __rv__sll8 (a, b);
}

/* { dg-final { scan-assembler "\tsll8" } }*/

/* { dg-final { cleanup-saved-temps } } */
