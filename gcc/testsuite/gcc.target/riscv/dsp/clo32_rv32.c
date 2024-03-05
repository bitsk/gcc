
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clo32(uintXLEN_t a) {
    return __rv__clo32 (a);
}

/* { dg-final { scan-assembler "\tclo32" } }*/

/* { dg-final { cleanup-saved-temps } } */
