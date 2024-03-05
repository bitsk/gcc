
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

unsigned int func (unsigned int a, unsigned int b)
{
  return (a & 0xffff0000) | (b & 0xffff);
}

/* { dg-final { scan-assembler "pktb16\ta0,a0,a1" } }*/

/* { dg-final { cleanup-saved-temps } } */
