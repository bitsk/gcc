
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3 --save-temps" } */

#if (__riscv_xlen==64)
#define N 8
#else
#define N 4
#endif

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
   a[i]= (b[i] + c[i]) >> 1;
}

/* { dg-final { scan-assembler "radd16\t" } }*/

void ufunc()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= (ub[i] + uc[i]) >> 1;
}

/* { dg-final { scan-assembler "uradd16\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

