
/* { dg-do assemble } */
/* { dg-options "-march=rv64gcp_zpsfoperand -mabi=lp64d -O2 --save-temps" } */

long long test_mulr64 (unsigned int a, unsigned int b) {
return (long long) a * b;
}

/* { dg-final { scan-assembler "mulr64\t" } }*/
/* { dg-final { cleanup-saved-temps } } */
