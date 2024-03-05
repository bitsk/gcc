
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uint16x4_t test_v_zunpkd831(uint8x8_t a) {
    return __rv__v_zunpkd831 (a);
}

/* { dg-final { scan-assembler "\tzunpkd831" } }*/

/* { dg-final { cleanup-saved-temps } } */
