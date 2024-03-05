
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_sunpkd832(uintXLEN_t a) {
    return __rv__sunpkd832 (a);
}

/* { dg-final { scan-assembler "\tsunpkd832" } }*/

/* { dg-final { cleanup-saved-temps } } */
