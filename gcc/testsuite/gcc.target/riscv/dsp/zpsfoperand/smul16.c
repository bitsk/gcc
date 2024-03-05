
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp_zpsfoperand -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_smul16(uint32_t a, uint32_t b) {
    return __rv__smul16 (a, b);
}

/* { dg-final { scan-assembler "\tsmul16" } }*/

/* { dg-final { cleanup-saved-temps } } */
