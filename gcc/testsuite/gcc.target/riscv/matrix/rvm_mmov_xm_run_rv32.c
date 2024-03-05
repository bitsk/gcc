/* { dg-do run } */
/* { dg-skip-if "test rv32 matrix" { *-*-* } { "*" } { "-march=rv32*xtheadmatrix*" } } */
/* { dg-options " -O2 " } */

#include <stdio.h>
#include <riscv_matrix.h>
#define N 8

int main ()
{
  /* Configuration matrix size */
  int mlen = mread_csr (RVM_XMLENB);
  int rlen = mread_csr (RVM_XRLENB);
  int clen = mlen/rlen;

  mcfgm (clen);
  mcfgn (clen);
  mcfgk (rlen);

  /* init data */
  int64_t src[N] = {0x10000000100, 0x10000000101, 0x10000000102, 0x10000000103};
  mint64_t ans = mld1m_i64 (src);

  int64_t value = mmov_xm_i64 (ans, 2);
  printf ("0x%0llx\n",value);

  return 0;
}
/* { dg-output "0x10000000102\r\n" } */
