
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

intXLEN_t test_kmmwb2_u(intXLEN_t a, uintXLEN_t b) {
    return __rv__kmmwb2_u (a, b);
}

/* { dg-final { scan-assembler "\tkmmwb2.u" } }*/

/* { dg-final { cleanup-saved-temps } } */
