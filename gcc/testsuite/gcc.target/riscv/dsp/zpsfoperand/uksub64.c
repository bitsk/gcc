
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp_zpsfoperand -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_uksub64(uint64_t a, uint64_t b) {
    return __rv__uksub64 (a, b);
}

/* { dg-final { scan-assembler "\tuksub64" } }*/

/* { dg-final { cleanup-saved-temps } } */
