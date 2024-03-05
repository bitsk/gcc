/* { dg-do run { target { riscv_rvv } } }
/* { dg-skip-if "test rvv32" { *-*-* } { "*" } { "-march=rv32*v*" } } */
/* { dg-options " -O2 " } */

#include <stdio.h>
#include <string.h>
#include <riscv_vector.h>

int64_t sample_int64[16] = {0x1ffffffff, 0x1ffffffff, 0x1ffffffff, 0x1ffffffff};
int64_t sample_int64_2[16] = {0x1eeeeeeee, 0x1eeeeeeee, 0x1eeeeeeee, 0x1eeeeeeee};
int64_t result_int64[16] = {};
int64_t scalar = (int64_t)1 << 40 + 1;

void vaddi64m1_i_masked_builtin_test(size_t n, int64_t *x, int64_t *y, int64_t z, size_t vl)
{
  vint64m1_t vx, vy;
  vbool64_t mask;
  vx = vle64_v_i64m1 (x, vl);
  vy = vle64_v_i64m1 (y, vl);
  vsetvl_e64m1 (vl);
  mask = vmset_m_b64 (vl);  vy = vsub_vx_i64m1_m (mask, vy, vx, scalar, vl);;

  vse64_v_i64m1 (y, vy, vl);
}
void rvvaddi64m1_i_masked_builtin_test_arg()
{
  int bytes = sizeof(sample_int64);
  int64_t a;
  union comp
  {
    int64_t origin;
    uint64_t memory;
  };
  union comp present;
  present.memory = 0;
  int len = bytes/sizeof(a);
  size_t vl = vsetvl_e64m1 (len);
  memcpy(result_int64, sample_int64_2, bytes);
  vaddi64m1_i_masked_builtin_test(1, sample_int64, result_int64, (int64_t)1, vl);
  for (int i=0; i< len; i++)
  {
    present.origin = result_int64[i];
    printf("%llx, ", present.memory);
  }
  printf("\n");
}
int main()
{
  vwrite_csr(RVV_VXRM, 2);
  rvvaddi64m1_i_masked_builtin_test_arg();
  return 0;
}
/* { dg-output "fffffe01ffffffff, fffffe01ffffffff, 1eeeeeeee, 1eeeeeeee, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \r\n" } */
