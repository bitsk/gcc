
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_zunpkd831(uintXLEN_t a) {
    return __rv__zunpkd831 (a);
}

/* { dg-final { scan-assembler "\tzunpkd831" } }*/

/* { dg-final { cleanup-saved-temps } } */
