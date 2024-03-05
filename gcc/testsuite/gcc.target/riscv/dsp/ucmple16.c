
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ucmple16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__ucmple16 (a, b);
}

/* { dg-final { scan-assembler "\tucmple16" } }*/

/* { dg-final { cleanup-saved-temps } } */
