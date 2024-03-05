
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

#include <riscv-dsp.h>

int8x4_t vec_set_qi(int8x4_t v, char a)
{
  v[3] = a;
  return v;
}

int16x2_t vec_set_si1(int16x2_t v, short a)
{
  v[0] = a;
  return v;
}

int16x2_t vec_set_si2(int16x2_t v, short a)
{
  v[1] = a;
  return v;
}

/* { dg-final { scan-assembler "insb\ta0,a1,3" } }*/
/* { dg-final { scan-assembler "pktb16\ta0,a0,a1" } }*/
/* { dg-final { scan-assembler "pkbb16\ta0,a1,a0" } }*/

/* { dg-final { cleanup-saved-temps } } */
