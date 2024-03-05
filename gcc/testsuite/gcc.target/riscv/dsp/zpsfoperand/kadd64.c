
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp_zpsfoperand -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int64_t test_kadd64(int64_t a, int64_t b) {
    return __rv__kadd64 (a, b);
}

/* { dg-final { scan-assembler "\tkadd64" } }*/

/* { dg-final { cleanup-saved-temps } } */
