
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_ucmple16(uint16x4_t a, uint16x4_t b) {
    return __rv__v_ucmple16 (a, b);
}

/* { dg-final { scan-assembler "\tucmple16" } }*/

/* { dg-final { cleanup-saved-temps } } */
