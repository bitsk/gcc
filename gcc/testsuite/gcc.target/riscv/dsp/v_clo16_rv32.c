
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x2_t test_v_clo16(uint16x2_t a) {
    return __rv__v_clo16 (a);
}

/* { dg-final { scan-assembler "\tclo16" } }*/

/* { dg-final { cleanup-saved-temps } } */
