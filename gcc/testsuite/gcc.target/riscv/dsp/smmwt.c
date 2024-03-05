
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smmwt(intXLEN_t a, uintXLEN_t b) {
    return __rv__smmwt (a, b);
}

/* { dg-final { scan-assembler "\tsmmwt" } }*/

/* { dg-final { cleanup-saved-temps } } */
