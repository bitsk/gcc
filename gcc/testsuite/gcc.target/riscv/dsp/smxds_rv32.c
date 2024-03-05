
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smxds(uintXLEN_t a, uintXLEN_t b) {
    return __rv__smxds (a, b);
}

/* { dg-final { scan-assembler "\tsmxds" } }*/

/* { dg-final { cleanup-saved-temps } } */
