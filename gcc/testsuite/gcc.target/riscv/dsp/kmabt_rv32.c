
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmabt(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__kmabt (t, a, b);
}

/* { dg-final { scan-assembler "\tkmabt" } }*/

/* { dg-final { cleanup-saved-temps } } */
