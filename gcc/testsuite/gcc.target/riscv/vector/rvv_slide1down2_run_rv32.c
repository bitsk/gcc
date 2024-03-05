/* { dg-do run { target { riscv_rvv } } }
/* { dg-skip-if "test rvv32" { *-*-* } { "*" } { "-march=rv32*v*" } } */
/* { dg-options " -O2 " } */

#include <stdio.h>
#include <string.h>
#include <riscv_vector.h>

uint64_t sample_uint64[16] = {
    0x1fffffffffffff, 189172ull, 805022ull,
    4144442ull, 712449ull, 517830ull,
    27064ull, 28349ull, 505349ull,
    823457ull, 84128ull, 2670377ull,
    70261ull, 56167ull, 5127434ull,
    630672ull};

uint64_t sample_uint64_2[16] = {
   0x1eeeeeeeeeeeee, 562095ull, 7477ull,
      56691ull, 99775ull, 71423ull,
      13218ull, 89426ull, 462010ull,
      63815ull, 63755ull, 6134ull,
      84790ull, 34518ull, 46ull,
      88968ull};

uint64_t result_uint64[16] = {};

void vslide1downu64m1_x_masked_builtin_test (uint64_t *x, uint64_t *y, uint64_t s, size_t vl)
{
    printf("testcase""vslide1down_vx_u64m1_m");
    printf("\n");
    vuint64m1_t vx, vy;
    vbool64_t mask;
    vsetvl_e64m1(vl);
    mask = vmset_m_b64 (vl);
    vx = vle64_v_u64m1 (x, vl);
    vy = vle64_v_u64m1 (y, vl);
    vx = vslide1down_vx_u64m1_m(mask, vy, vx, s, vl);
    vse64_v_u64m1 (x, vx, vl);
}
void rvvslide1downu64m1_x_masked_builtin_test_arg()
{
    printf("start test: %s\n", __FUNCTION__);
    int bytes = sizeof(sample_uint64 );
    uint64_t a;
    union comp
    {
        uint64_t origin;
        uint64_t memory;
    };
    union comp present;
    present.memory = 0;
    int len = bytes/sizeof(a);
    size_t vl = vsetvl_e64m1 (len);
    memcpy(result_uint64, sample_uint64, bytes);
    vslide1downu64m1_x_masked_builtin_test(result_uint64, sample_uint64_2, (uint64_t)0x1fffffffffffff, vl);
    for (int i=0; i< len; i++)
    {
        present.origin = result_uint64[i];
        printf("%llx, ", present.memory);
    }
    printf("\n");
    printf("end test.\n");
}
int main()
{
  vwrite_csr(RVV_VXRM, 2);
  rvvslide1downu64m1_x_masked_builtin_test_arg();
  return 0;
}
/* { dg-output "testcasevslide1down_vx_u64m1_m\r\n" } */
/* { dg-output "2e2f4, 1fffffffffffff, c489e, 3f3d3a, adf01, 7e6c6, 69b8, 6ebd, 7b605, c90a1, 148a0, 28bf29, 11275, db67, 4e3d0a, 99f90, \r\n" } */
