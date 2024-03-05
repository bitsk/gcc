/* { dg-do run { target { riscv_rvv } } }
/* { dg-skip-if "test rvv32" { *-*-* } { "*" } { "-march=rv32*v*" } } */
/* { dg-options " -O2 " } */

#include <stdio.h>
#include <string.h>
#include <riscv_vector.h>

const int64_t sample_int64[16] = {0x1fffffffffffff, 0x1fffffffffffff, 0x1fffffffffffff, 0x1fffffffffffff};
int64_t result_int64[16] = {};
int64_t scalar = (int64_t)1 << 33 + 1;

int main()
{
  size_t vl = 128;
  vint64m1_t value, output_var_0;

  value = vle64_v_i64m1(&sample_int64[0], vl);
  output_var_0 = vadd_vx_i64m1 (value, scalar, vl);

  memcpy(result_int64, sample_int64, sizeof(sample_int64));
  vse64_v_i64m1(&result_int64[0], output_var_0, vl);
  union comp
  {
    int64_t origin;
    uint64_t memory;
  };
  union comp present;
  present.memory = 0;
  for (int i = 0; i < 2; i++)
  {
    present.origin = result_int64[i];
    printf("%llx, ", present.memory);
  }
  printf("\n");
  return 0;
}

/* { dg-output "200003ffffffff, 200003ffffffff, \r\n" } */
