
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2 --save-temps" } */

int func(int a)
{
  return __builtin_clrsb (a);
}

/* { dg-final { scan-assembler "clrs32\ta0,a0" } }*/

/* { dg-final { cleanup-saved-temps } } */

