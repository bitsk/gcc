
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

long long test_mulsr64 (int a, int b) {
return (long long) a * b;
}

/* { dg-final { scan-assembler "mulsr64\t" } }*/
/* { dg-final { cleanup-saved-temps } } */
