
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int8x8_t test_v_khmx8(int8x8_t a, int8x8_t b) {
    return __rv__v_khmx8 (a, b);
}

/* { dg-final { scan-assembler "\tkhmx8" } }*/

/* { dg-final { cleanup-saved-temps } } */
