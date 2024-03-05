
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint64_t test_smulx16(uint32_t a, uint32_t b) {
    return __rv__smulx16 (a, b);
}

/* { dg-final { scan-assembler "\tsmulx16" } }*/

/* { dg-final { cleanup-saved-temps } } */
