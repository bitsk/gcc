
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3 --save-temps" } */

#if (__riscv_xlen==64)
#define N 8
#else
#define N 4
#endif

signed char a[N];
signed char b[N];
signed char c[N];
unsigned char ua[N];
unsigned char ub[N];
unsigned char uc[N];

void func()
{
  int i;
  for (i=0;i<N;i++)
   a[i]= b[i]<c[i] ? b[i] : c[i];
}

/* { dg-final { scan-assembler "smin8\t" } }*/

void ufunc()
{
  int i;
  for (i=0;i<N;i++)
   ua[i]= ub[i]<uc[i] ? ub[i] : uc[i];
}

/* { dg-final { scan-assembler "umin8\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

