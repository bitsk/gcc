/* { dg-do run } */
/* { dg-skip-if "test rv32 matrix" { *-*-* } { "*" } { "-march=rv32*xtheadmatrix*" } } */
/* { dg-options " -O2 " } */

#include <stdio.h>
#include <riscv_matrix.h>
#define N 8

void
print_data (mint64_t ma)
{
  int64_t tmp_ma[N] = {-1, -1, -1, -1, -1, -1, -1, -1};

  mst1m_i64_mi64 (tmp_ma, ma);
  for (int i=0;i<N;i++)
    printf ("0x%0llx ", tmp_ma[i]);

  printf ("\n");
}

void test (int64_t value)
{
  int64_t date[8] = {0x10000000100, 0x10000000101, 0x10000000102, 0x10000000103};
  mint64_t src = mld1m_i64 (date);
  mint64_t ans = msub_mi64_i64 (src, value);
  print_data (ans);        
}


int main ()
{
  /* init data */
  uint64_t src = (uint64_t)0x10000000101;

  /* Configuration matrix size */
  int mlen = mread_csr (RVM_XMLENB);
  int rlen = mread_csr (RVM_XRLENB);
  int clen = mlen/rlen;
  
  mcfgm (clen);
  mcfgn (clen);
  mcfgk (rlen);

  test (src);
  
  return 0;
}

/* { dg-output "0xffffffffffffffff 0x0 0x1 0x2 0xfffffefffffffeff 0xfffffefffffffeff 0xfffffefffffffeff 0xfffffefffffffeff \r\n" } */
