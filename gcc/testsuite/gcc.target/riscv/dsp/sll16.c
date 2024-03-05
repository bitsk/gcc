
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sll16(uintXLEN_t a, uint32_t b) {
    return __rv__sll16 (a, b);
}

/* { dg-final { scan-assembler "\tsll16" } }*/

/* { dg-final { cleanup-saved-temps } } */
