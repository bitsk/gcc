
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_khmbb(uint32_t a, uint32_t b) {
    return __rv__khmbb (a, b);
}

/* { dg-final { scan-assembler "\tkhmbb" } }*/

/* { dg-final { cleanup-saved-temps } } */
