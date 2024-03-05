
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int32_t test_kdmbt(uint32_t a, uint32_t b) {
    return __rv__kdmbt (a, b);
}

/* { dg-final { scan-assembler "\tkdmbt" } }*/

/* { dg-final { cleanup-saved-temps } } */
