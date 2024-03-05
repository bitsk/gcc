
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3 --save-temps" } */

unsigned int a[2];
unsigned int b[2]={1,2};
unsigned int c[2]={0,7};
int i;

void func()
{
  for (i=0;i<2;i++)
   a[i]= b[i]<c[i] ? b[i] : c[i];
}

/* { dg-final { scan-assembler "umin32\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

