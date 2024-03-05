
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kwmmul(intXLEN_t a, intXLEN_t b) {
    return __rv__kwmmul (a, b);
}

/* { dg-final { scan-assembler "\tkwmmul" } }*/

/* { dg-final { cleanup-saved-temps } } */
