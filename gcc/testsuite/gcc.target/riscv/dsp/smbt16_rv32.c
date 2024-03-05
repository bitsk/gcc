
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smbt16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__smbt16 (a, b);
}

/* { dg-final { scan-assembler "\tsmbt16" } }*/

/* { dg-final { cleanup-saved-temps } } */
