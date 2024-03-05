
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp_zpsfoperand -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_v_ukmar64(uint64_t t, uint32x2_t a, uint32x2_t b) {
    return __rv__v_ukmar64 (t, a, b);
}

/* { dg-final { scan-assembler "\tukmar64" } }*/

/* { dg-final { cleanup-saved-temps } } */
