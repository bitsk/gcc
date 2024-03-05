
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3 --save-temps" } */

#define N 4

signed short a[N];
signed short b[N];
signed short c[N];
unsigned short ua[N];
unsigned short ub[N];
unsigned short uc[N];

void func()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i] + c[i];
}

/* { dg-final { scan-assembler "add16\t" } }*/

void ufunc()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i] + uc[i];
}

/* { dg-final { scan-assembler "add16\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

