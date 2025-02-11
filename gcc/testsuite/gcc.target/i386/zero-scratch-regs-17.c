/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -fzero-call-used-regs=used" } */

int
foo (int x)
{
  return x;
}

/* { dg-final { scan-assembler-not "vzeroall" } } */
/* { dg-final { scan-assembler-not "%xmm" } } */
/* { dg-final { scan-assembler-not "xorl\[ \t\]*%" { target ia32 } } } */
/* { dg-final { scan-assembler "xorl\[ \t\]*%edi, %edi" { target { ! ia32 } } } } */
