
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_uksub16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__uksub16 (a, b);
}

/* { dg-final { scan-assembler "\tuksub16" } }*/

/* { dg-final { cleanup-saved-temps } } */
