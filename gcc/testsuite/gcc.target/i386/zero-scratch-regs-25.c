/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -fzero-call-used-regs=used-arg" } */

int 
foo (int x)
{
  return x;
}

/* { dg-final { scan-assembler "xorl\[ \t\]*%edi, %edi" } } */
