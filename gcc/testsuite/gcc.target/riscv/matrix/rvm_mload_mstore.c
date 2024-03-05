/* { dg-do compile } */
/* { dg-options "-march=rv64gcxtheadmatrix -mabi=lp64d -O2" } */

#include <riscv_matrix.h>
#include <stddef.h>
#include "rvm-common.h"

#define MTEST(TYPE_T, STYPE, TYPE)  \
  void test_mload_store_##TYPE(long stride, TYPE_T *x, TYPE_T *y) {  \
    m##TYPE_T temp1 = mld_##STYPE (x, stride);  \
    mst_##STYPE##_m##STYPE (y, stride, temp1);  \
    m##TYPE_T temp2 = msld_##STYPE (x, stride);  \
    msst_##STYPE##_m##STYPE (y, stride, temp2);  \
  }

RVM_ALL_TYPE_TEST(MTEST)

/* { dg-final { scan-assembler-times "mldb\t" 2 } } */
/* { dg-final { scan-assembler-times "mstb\t" 2 } } */
/* { dg-final { scan-assembler-times "mldh\t" 3 } } */
/* { dg-final { scan-assembler-times "msth\t" 3 } } */
/* { dg-final { scan-assembler-times "mldw\t" 3 } } */
/* { dg-final { scan-assembler-times "mstw\t" 3 } } */
/* { dg-final { scan-assembler-times "mldd\t" 3 } } */
/* { dg-final { scan-assembler-times "mstd\t" 3 } } */
/* { dg-final { scan-assembler-times "msldb\t" 2 } } */
/* { dg-final { scan-assembler-times "msstb\t" 2 } } */
/* { dg-final { scan-assembler-times "msldh\t" 3 } } */
/* { dg-final { scan-assembler-times "mssth\t" 3 } } */
/* { dg-final { scan-assembler-times "msldw\t" 3 } } */
/* { dg-final { scan-assembler-times "msstw\t" 3 } } */
/* { dg-final { scan-assembler-times "msldd\t" 3 } } */
/* { dg-final { scan-assembler-times "msstd\t" 3 } } */
