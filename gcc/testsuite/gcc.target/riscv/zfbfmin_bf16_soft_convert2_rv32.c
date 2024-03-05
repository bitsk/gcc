/* { dg-do compile } */
/* { dg-options "-march=rv32imac -mabi=ilp32 -O" } */

extern __bf16 a;
extern __bf16 b;

float foo() {
  return a/b;
}

/* { dg-final { scan-assembler-times "call\t__truncsfbf2" "1" } } */
