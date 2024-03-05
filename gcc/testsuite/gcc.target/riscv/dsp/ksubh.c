
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_ksubh(int32_t a, int32_t b) {
    return __rv__ksubh (a, b);
}

/* { dg-final { scan-assembler "\tksubh" } }*/

/* { dg-final { cleanup-saved-temps } } */
