
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_rsubw(int32_t a, int32_t b) {
    return __rv__rsubw (a, b);
}

/* { dg-final { scan-assembler "\trsubw" } }*/

/* { dg-final { cleanup-saved-temps } } */
