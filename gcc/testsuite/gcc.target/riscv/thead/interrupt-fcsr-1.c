/* Verify that fcsr instructions emitted.  */
/* { dg-do compile } */
/* { dg-require-effective-target hard_float } */
/* { dg-options "-O" } */

extern int foo (void);

void __attribute__ ((interrupt))
sub (void)
{
  foo ();
}

/* { dg-final { scan-assembler-times "frcsr\tt0" 1 } } */
/* { dg-final { scan-assembler-times "fscsr\tt0" 1 } } */