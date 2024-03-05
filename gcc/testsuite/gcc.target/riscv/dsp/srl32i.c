
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_srl32(uintXLEN_t a, const uint32_t b) {
    return __rv__srl32 (a, 1);
}

/* { dg-final { scan-assembler "\tsrli32" } }*/

/* { dg-final { cleanup-saved-temps } } */
