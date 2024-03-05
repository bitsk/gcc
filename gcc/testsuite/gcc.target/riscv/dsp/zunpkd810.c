
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_zunpkd810(uintXLEN_t a) {
    return __rv__zunpkd810 (a);
}

/* { dg-final { scan-assembler "\tzunpkd810" } }*/

/* { dg-final { cleanup-saved-temps } } */
