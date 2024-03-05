
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O2 --save-temps" } */

#include <riscv-dsp.h>

int8x8_t vec_set_qi(int8x8_t v, char a)
{
  v[5] = a;
  return v;
}

int32x2_t vec_set_si1(int32x2_t v, int a)
{
  v[0] = a;
  return v;
}

int32x2_t vec_set_si2(int32x2_t v, int a)
{
  v[1] = a;
  return v;
}

/* { dg-final { scan-assembler "insb\ta0,a1,5" } }*/
/* { dg-final { scan-assembler "pktb32\ta0,a0,a1" } }*/
/* { dg-final { scan-assembler "pkbb32\ta0,a1,a0" } }*/

/* { dg-final { cleanup-saved-temps } } */
