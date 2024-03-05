/* { dg-do compile } */
/* { dg-options "-march=rv64imac -mabi=lp64 -O0" } */

extern __bf16 a;
extern __bf16 b;
extern  void abort();

void foo() {
  if (a != b) {
    abort();
  }
}

/* { dg-final { scan-assembler-not "call\t__nebf2" } } */