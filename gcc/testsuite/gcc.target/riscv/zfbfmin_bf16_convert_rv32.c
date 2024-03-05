/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zfbfmin_zfh -mabi=ilp32d -O" } */

extern __bf16 bf;
extern __bf16 bf1;
extern __bf16 bf2;
extern __fp16 hf;
extern float sf;
extern double df;

extern int si;
extern long long  di;

extern unsigned int usi;
extern unsigned long long udi;

/* Fp or gp Converts to bf.  */
void hf_to_bf () { bf = hf; }

void sf_to_bf () { bf = sf; }

void df_to_bf () { bf = df; }

void si_to_bf () { bf = si; }

void di_to_bf () { bf = di; } /* call\t__floatdisf + fcvt.bf16.s.  */

void usi_to_bf () { bf = usi; }

void udi_to_bf () { bf = udi; } /* call\t__floatundisf + fcvt.bf16.s. */

void const_to_bf () { __volatile__ float temp = 3.14; bf = temp; }

/* bf converts to fp or gp.  */
void bf_to_hf () { hf = bf; }

void bf_to_sf () { sf = bf; }

void bf_to_df () { df = bf; }

void bf_to_si () { si = bf; }

void bf_to_di () { di = bf; } /* fcvt.s.bf16 + call\t__fixsfdi. */

void bf_to_usi () { usi = bf; }

void bf_to_udi () { udi = bf; } /* fcvt.s.bf16 + call\t__fixunssfdi. */

/* arithmetic operation.  */
void bf_add_bf () { bf = bf1 + bf2; }

void bf_sub_bf () { bf = bf1 - bf2; }

void bf_mul_bf () { bf = bf1 * bf2; }

void bf_div_bf () { bf = bf1 / bf2; }

void bf_add_const () { bf = bf1 + 3.14; }

void const_sub_bf () { bf = 3.14 - bf2; }

void bf_mul_const () { bf = bf1 *3.14; }

void const_div_bf () { bf = 3.14 / bf2; }

void bf_inc () { ++bf; }

void bf_dec () { --bf; }

/* logical operation.  */
void bf_lt_bf () { bf = (bf1 < bf2) ? bf1 : bf2; }

void bf_gt_bf () { bf = (bf1 > bf2) ? bf1 : bf2; }

void bf_eq_bf () { bf = (bf1 == bf2) ? bf1 : bf2; }

void bf_lt_const () { bf = (bf1 < 3.14) ? bf1 : bf2; }

void const_gt_bf () { bf = (3.14 > bf2) ? bf1 : bf2; }

void bf_eq_const () { bf = (bf1 == 3.14) ? bf1 : bf2; }

/* { dg-final { scan-assembler-times "fcvt.s.bf16" 32 } } */
/* { dg-final { scan-assembler-times "fcvt.bf16.s" 18 } } */
