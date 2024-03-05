/* { dg-do run } */
/* { dg-skip-if "test rv32 matrix" { *-*-* } { "*" } { "-march=rv32*xtheadmatrix*" } } */
/* { dg-options " -O2 " } */

#include <stdio.h>
#include <riscv_matrix.h>
#define N 8

void
print_data (mint8_t ma)
{
  int8_t tmp_ma[N] = {-1, -1, -1, -1, -1, -1, -1, -1};

  mst1m_i8_mi8 (tmp_ma, ma);
  for (int i=0;i<N;i++)
    printf ("0x%0x ", tmp_ma[i]);

  printf ("\n");
}

void test (uint64_t value)
{
  int64_t date[8] = {0x10000000100, 0x10000000101, 0x10000000102, 0x10000000103};
  mint64_t src = mld1m_i64 (date);
  mint8_t ans = mn4clip_mi64_ui64 (src, value);
  print_data ( ans);        
}

int main ()
{
  int mlen = mread_csr (RVM_XMLENB);
  int rlen = mread_csr (RVM_XRLENB);
  int clen = mlen/rlen;
  /* init data */
  uint64_t src = (uint64_t)0x10000000101;

  uint8_t msize_m = clen;
  uint8_t msize_n = clen;
  uint16_t msize_k = rlen; // sizeof (int64_t) * 2;

  /* Configuration matrix size */
  mcfgm (msize_m);
  mcfgn (msize_n);
  mcfgk (msize_k);

  test (src);
  return 0;
}

/* { dg-output "0xffffffff 0x7f 0xffffffff 0x7f 0x0 0x1 0x0 0x0 \r\n" } */
