
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_v_khmbb(int16x2_t a, int16x2_t b) {
    return __rv__v_khmbb (a, b);
}

/* { dg-final { scan-assembler "\tkhmbb" } }*/

/* { dg-final { cleanup-saved-temps } } */
