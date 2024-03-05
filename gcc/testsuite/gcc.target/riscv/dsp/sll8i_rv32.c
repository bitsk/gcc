
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sll8(uintXLEN_t a, const uint32_t b) {
    return __rv__sll8 (a, 1);
}

/* { dg-final { scan-assembler "\tslli8" } }*/

/* { dg-final { cleanup-saved-temps } } */
