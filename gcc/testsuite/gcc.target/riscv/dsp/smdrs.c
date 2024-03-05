
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smdrs(uintXLEN_t a, uintXLEN_t b) {
    return __rv__smdrs (a, b);
}

/* { dg-final { scan-assembler "\tsmdrs" } }*/

/* { dg-final { cleanup-saved-temps } } */
