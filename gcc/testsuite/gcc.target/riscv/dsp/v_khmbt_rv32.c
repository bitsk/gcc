
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_v_khmbt(int16x2_t a, int16x2_t b) {
    return __rv__v_khmbt (a, b);
}

/* { dg-final { scan-assembler "\tkhmbt" } }*/

/* { dg-final { cleanup-saved-temps } } */
