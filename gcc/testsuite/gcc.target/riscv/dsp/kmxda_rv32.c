
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmxda(uintXLEN_t a, uintXLEN_t b) {
    return __rv__kmxda (a, b);
}

/* { dg-final { scan-assembler "\tkmxda" } }*/

/* { dg-final { cleanup-saved-temps } } */
