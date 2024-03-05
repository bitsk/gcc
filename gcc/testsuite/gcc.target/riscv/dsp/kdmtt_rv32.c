
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_kdmtt(uint32_t a, uint32_t b) {
    return __rv__kdmtt (a, b);
}

/* { dg-final { scan-assembler "\tkdmtt" } }*/

/* { dg-final { cleanup-saved-temps } } */
