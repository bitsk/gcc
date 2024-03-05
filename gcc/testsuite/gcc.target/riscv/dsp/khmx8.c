
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_khmx8(uintXLEN_t a, uintXLEN_t b) {
    return __rv__khmx8 (a, b);
}

/* { dg-final { scan-assembler "\tkhmx8" } }*/

/* { dg-final { cleanup-saved-temps } } */
