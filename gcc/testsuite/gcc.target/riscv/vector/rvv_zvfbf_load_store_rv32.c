/* { dg-do compile } */
/* { dg-options "-march=rv32gcv_zvfbfmin -mabi=ilp32d -O2" } */

#include <riscv_vector.h>

vbfloat16mf4_t testvle16_v_bf16mf4(const bfloat16_t *base, size_t vl){ return vle16_v_bf16mf4(base,vl);}
vbfloat16mf2_t testvle16_v_bf16mf2(const bfloat16_t *base, size_t vl){ return vle16_v_bf16mf2(base,vl);}
vbfloat16m1_t testvle16_v_bf16m1(const bfloat16_t *base, size_t vl){ return vle16_v_bf16m1(base,vl);}
vbfloat16m2_t testvle16_v_bf16m2(const bfloat16_t *base, size_t vl){ return vle16_v_bf16m2(base,vl);}
vbfloat16m4_t testvle16_v_bf16m4(const bfloat16_t *base, size_t vl){ return vle16_v_bf16m4(base,vl);}
vbfloat16m8_t testvle16_v_bf16m8(const bfloat16_t *base, size_t vl){ return vle16_v_bf16m8(base,vl);}
vbfloat16mf4_t testvle16_v_bf16mf4_m(vbool64_t mask, vbfloat16mf4_t maskedoff, const bfloat16_t *base, size_t vl){ return vle16_v_bf16mf4_m(mask,maskedoff,base,vl);}
vbfloat16mf2_t testvle16_v_bf16mf2_m(vbool32_t mask, vbfloat16mf2_t maskedoff, const bfloat16_t *base, size_t vl){ return vle16_v_bf16mf2_m(mask,maskedoff,base,vl);}
vbfloat16m1_t testvle16_v_bf16m1_m(vbool16_t mask, vbfloat16m1_t maskedoff, const bfloat16_t *base, size_t vl){ return vle16_v_bf16m1_m(mask,maskedoff,base,vl);}
vbfloat16m2_t testvle16_v_bf16m2_m(vbool8_t mask, vbfloat16m2_t maskedoff, const bfloat16_t *base, size_t vl){ return vle16_v_bf16m2_m(mask,maskedoff,base,vl);}
vbfloat16m4_t testvle16_v_bf16m4_m(vbool4_t mask, vbfloat16m4_t maskedoff, const bfloat16_t *base, size_t vl){ return vle16_v_bf16m4_m(mask,maskedoff,base,vl);}
vbfloat16m8_t testvle16_v_bf16m8_m(vbool2_t mask, vbfloat16m8_t maskedoff, const bfloat16_t *base, size_t vl){ return vle16_v_bf16m8_m(mask,maskedoff,base,vl);}

void testvse16_v_bf16mf4(bfloat16_t *base, vbfloat16mf4_t value, size_t vl){ return vse16_v_bf16mf4(base,value,vl);}
void testvse16_v_bf16mf2(bfloat16_t *base, vbfloat16mf2_t value, size_t vl){ return vse16_v_bf16mf2(base,value,vl);}
void testvse16_v_bf16m1(bfloat16_t *base, vbfloat16m1_t value, size_t vl){ return vse16_v_bf16m1(base,value,vl);}
void testvse16_v_bf16m2(bfloat16_t *base, vbfloat16m2_t value, size_t vl){ return vse16_v_bf16m2(base,value,vl);}
void testvse16_v_bf16m4(bfloat16_t *base, vbfloat16m4_t value, size_t vl){ return vse16_v_bf16m4(base,value,vl);}
void testvse16_v_bf16m8(bfloat16_t *base, vbfloat16m8_t value, size_t vl){ return vse16_v_bf16m8(base,value,vl);}
void testvse16_v_bf16mf4_m(vbool64_t mask, bfloat16_t *base, vbfloat16mf4_t value, size_t vl){ return vse16_v_bf16mf4_m(mask,base,value,vl);}
void testvse16_v_bf16mf2_m(vbool32_t mask, bfloat16_t *base, vbfloat16mf2_t value, size_t vl){ return vse16_v_bf16mf2_m(mask,base,value,vl);}
void testvse16_v_bf16m1_m(vbool16_t mask, bfloat16_t *base, vbfloat16m1_t value, size_t vl){ return vse16_v_bf16m1_m(mask,base,value,vl);}
void testvse16_v_bf16m2_m(vbool8_t mask, bfloat16_t *base, vbfloat16m2_t value, size_t vl){ return vse16_v_bf16m2_m(mask,base,value,vl);}
void testvse16_v_bf16m4_m(vbool4_t mask, bfloat16_t *base, vbfloat16m4_t value, size_t vl){ return vse16_v_bf16m4_m(mask,base,value,vl);}
void testvse16_v_bf16m8_m(vbool2_t mask, bfloat16_t *base, vbfloat16m8_t value, size_t vl){ return vse16_v_bf16m8_m(mask,base,value,vl);}

/* { dg-final { scan-assembler-times "vle16.v\t" 12 } } */
/* { dg-final { scan-assembler-times "vse16.v\t" 12 } } */



