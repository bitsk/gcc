/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32d" } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

void vsloadstore64i8mf8(size_t n, long stride, int8_t *x, int8_t *y, int8_t z, uint64_t *index, word_type vl)
{
  vint8mf8_t vx, vy, vz;
  vuint64m1_t vindex;
  vbool64_t mask;
  mask = vmset_m_b64(vl);
  vindex = vle64_v_u64m1(index, vl);
  vx = vle8_v_i8mf8(x, vl);
  vy = vle8_v_i8mf8(y, vl);
  vz = vadd_vv_i8mf8(vx, vy, vl);
  vsoxei64_v_i8mf8_m(mask, x, vindex, vz, vl);
  /* { dg-error "Invalid function __builtin_riscv_vsoxeii8mf8_64m1_si_mask for vector on rv32" "" { target *-*-* } 0 } */
}
void vusloadstore64i8mf8(size_t n, long stride, int8_t *x, int8_t *y, int8_t z, uint64_t *index, word_type vl)
{
  vint8mf8_t vx, vy, vz;
  vuint64m1_t vindex;
  vbool64_t mask;
  mask = vmset_m_b64(vl);
  vindex = vle64_v_u64m1(index, vl);
  vx = vle8_v_i8mf8(x, vl);
  vy = vle8_v_i8mf8(y, vl);
  vz = vadd_vv_i8mf8(vx, vy, vl);
  vsuxei64_v_i8mf8_m(mask, x, vindex, vz, vl);
  /* { dg-error "Invalid function __builtin_riscv_vsuxeii8mf8_64m1_si_mask for vector on rv32" "" { target *-*-* } 0 } */
}

void vsloadstore64u8mf8(size_t n, long stride, uint8_t *x, uint8_t *y, uint8_t z, uint64_t *index, word_type vl)
{
  vuint8mf8_t vx, vy, vz;
  vuint64m1_t vindex;
  vbool64_t mask;
  mask = vmset_m_b64(vl);
  vindex = vle64_v_u64m1(index, vl);
  vx = vle8_v_u8mf8(x, vl);
  vy = vle8_v_u8mf8(y, vl);
  vz = vadd_vv_u8mf8(vx, vy, vl);
  vsoxei64_v_u8mf8_m(mask, x, vindex, vz, vl);
  /* { dg-error "Invalid function __builtin_riscv_vsoxeiu8mf8_64m1_si_mask for vector on rv32" "" { target *-*-* } 0 } */
}
void vusloadstore64u8mf8(size_t n, long stride, uint8_t *x, uint8_t *y, uint8_t z, uint64_t *index, word_type vl)
{
  vuint8mf8_t vx, vy, vz;
  vuint64m1_t vindex;
  vbool64_t mask;
  mask = vmset_m_b64(vl);
  vindex = vle64_v_u64m1(index, vl);
  vx = vle8_v_u8mf8(x, vl);
  vy = vle8_v_u8mf8(y, vl);
  vz = vadd_vv_u8mf8(vx, vy, vl);
  vsuxei64_v_u8mf8_m(mask, x, vindex, vz, vl);
  /* { dg-error "Invalid function __builtin_riscv_vsuxeiu8mf8_64m1_si_mask for vector on rv32" "" { target *-*-* } 0 } */
}

void vsloadstore64f16mf4(size_t n, long stride, float16_t *x, float16_t *y, float16_t z, uint64_t *index, word_type vl)
{
  vfloat16mf4_t vx, vy, vz;
  vuint64m1_t vindex;
  vbool64_t mask;
  mask = vmset_m_b64(vl);
  vindex = vle64_v_u64m1(index, vl);
  vx = vle16_v_f16mf4(x, vl);
  vy = vle16_v_f16mf4(y, vl);
  vz = vfadd_vv_f16mf4(vx, vy, vl);
  vsoxei64_v_f16mf4_m(mask, x, vindex, vz, vl);
  /* { dg-error "Invalid function __builtin_riscv_vsoxeif16mf4_64m1_si_mask for vector on rv32" "" { target *-*-* } 0 } */
}
void vusloadstore64f16mf4(size_t n, long stride, float16_t *x, float16_t *y, float16_t z, uint64_t *index, word_type vl)
{
  vfloat16mf4_t vx, vy, vz;
  vuint64m1_t vindex;
  vbool64_t mask;
  mask = vmset_m_b64(vl);
  vindex = vle64_v_u64m1(index, vl);
  vx = vle16_v_f16mf4(x, vl);
  vy = vle16_v_f16mf4(y, vl);
  vz = vfadd_vv_f16mf4(vx, vy, vl);
  vsuxei64_v_f16mf4_m(mask, x, vindex, vz, vl);
  /* { dg-error "Invalid function __builtin_riscv_vsuxeif16mf4_64m1_si_mask for vector on rv32" "" { target *-*-* } 0 } */
}
