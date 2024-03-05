
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_kabs8(uintXLEN_t a) {
    return __rv__kabs8 (a);
}

/* { dg-final { scan-assembler "\tkabs8" } }*/

/* { dg-final { cleanup-saved-temps } } */
