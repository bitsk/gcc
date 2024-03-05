
/* { dg-do assemble } */
/* { dg-options "-march=rv32gcp_zpsfoperand -mabi=ilp32d -O2 --save-temps" } */

long long test_smar64(long long t, int a, int b) {
    return t + (long long)a * (long long)b;
}

/* { dg-final { scan-assembler "\tsmar64" } }*/

/* { dg-final { cleanup-saved-temps } } */
