
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_kdmbb(uint32_t a, uint32_t b) {
    return __rv__kdmbb (a, b);
}

/* { dg-final { scan-assembler "\tkdmbb" } }*/

/* { dg-final { cleanup-saved-temps } } */
