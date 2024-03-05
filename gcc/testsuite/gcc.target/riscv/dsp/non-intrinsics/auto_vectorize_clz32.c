
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3 --save-temps" } */

int a[2];
unsigned int b[2];

void func()
{
  int i;
  for (i = 0; i < 2; i++)
   a[i] = __builtin_clz (b[i]);
}

/* { dg-final { scan-assembler-times "clz32\t" 1 } }*/

/* { dg-final { cleanup-saved-temps } } */

