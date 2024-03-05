
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smmwb(intXLEN_t a, uintXLEN_t b) {
    return __rv__smmwb (a, b);
}

/* { dg-final { scan-assembler "\tsmmwb" } }*/

/* { dg-final { cleanup-saved-temps } } */
