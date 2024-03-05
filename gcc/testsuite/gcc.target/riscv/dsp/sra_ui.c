
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_sra_u(intXLEN_t a, const uint32_t b) {
    return __rv__sra_u (a, 1);
}

/* { dg-final { scan-assembler "\tsrai.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
