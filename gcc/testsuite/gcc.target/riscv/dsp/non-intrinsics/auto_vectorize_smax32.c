
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3 --save-temps" } */

int a[2];
int b[2]={1,2};
int c[2]={0,7};
int i;

void func()
{
  for (i=0;i<2;i++)
   a[i]= b[i]>c[i] ? b[i] : c[i];
}

/* { dg-final { scan-assembler "smax32\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

