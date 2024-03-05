
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_wext(uint64_t a, uint32_t b) {
    return __rv__wext (a, b);
}

/* { dg-final { scan-assembler "\twext" } }*/

/* { dg-final { cleanup-saved-temps } } */
