
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_clo16(uintXLEN_t a) {
    return __rv__clo16 (a);
}

/* { dg-final { scan-assembler "\tclo16" } }*/

/* { dg-final { cleanup-saved-temps } } */
