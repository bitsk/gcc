
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmaxda(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
    return __rv__kmaxda (t, a, b);
}

/* { dg-final { scan-assembler "\tkmaxda" } }*/

/* { dg-final { cleanup-saved-temps } } */
