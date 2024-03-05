
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kwmmul_u(intXLEN_t a, intXLEN_t b) {
    return __rv__kwmmul_u (a, b);
}

/* { dg-final { scan-assembler "\tkwmmul.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
