
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

uintXLEN_t test_ursubw(uint32_t a, uint32_t b) {
    return __rv__ursubw (a, b);
}

/* { dg-final { scan-assembler "\tursubw" } }*/

/* { dg-final { cleanup-saved-temps } } */
