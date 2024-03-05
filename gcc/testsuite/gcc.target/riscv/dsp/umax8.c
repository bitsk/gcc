
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_umax8(uintXLEN_t a, uintXLEN_t b) {
    return __rv__umax8 (a, b);
}

/* { dg-final { scan-assembler "\tumax8" } }*/

/* { dg-final { cleanup-saved-temps } } */
