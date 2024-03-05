/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d -mrvv-vector-bits=128" } */

#include <riscv_vector.h>

/* Sizeless objects with global scope.  */

vint8m1_t global_rvv_sc;
static vint8m1_t local_rvv_sc;
extern vint8m1_t extern_rvv_sc;
__thread vint8m1_t tls_rvv_sc;
_Atomic vint8m1_t atomic_rvv_sc;

struct rvv_fixed
{
  vfloat32m1_t a;
  vfloat32m1_t b;
}x;