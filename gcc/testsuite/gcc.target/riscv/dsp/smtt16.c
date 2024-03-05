
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_smtt16(uintXLEN_t a, uintXLEN_t b) {
    return __rv__smtt16 (a, b);
}

/* { dg-final { scan-assembler "\tsmtt16" } }*/

/* { dg-final { cleanup-saved-temps } } */
