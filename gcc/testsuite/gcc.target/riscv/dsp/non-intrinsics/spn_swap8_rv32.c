
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

unsigned short func(unsigned short a)
{
  return (a << 8) | (a >> 8);
}

/* { dg-final { scan-assembler "swap8\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

