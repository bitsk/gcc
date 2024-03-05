/* { dg-do compile } */
/* { dg-options "-march=rv32gcv_zvfbfwma -mabi=ilp32d -O2" } */

#include <riscv_vector.h>

vfloat32mf2_t testvfwmaccbf16_vv_f32mf2(vfloat32mf2_t vd, vbfloat16mf4_t vs1, vbfloat16mf4_t vs2, size_t vl){ return vfwmaccbf16_vv_f32mf2(vd,vs1,vs2,vl);}
vfloat32m1_t testvfwmaccbf16_vv_f32m1(vfloat32m1_t vd, vbfloat16mf2_t vs1, vbfloat16mf2_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m1(vd,vs1,vs2,vl);}
vfloat32m2_t testvfwmaccbf16_vv_f32m2(vfloat32m2_t vd, vbfloat16m1_t vs1, vbfloat16m1_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m2(vd,vs1,vs2,vl);}
vfloat32m4_t testvfwmaccbf16_vv_f32m4(vfloat32m4_t vd, vbfloat16m2_t vs1, vbfloat16m2_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m4(vd,vs1,vs2,vl);}
vfloat32m8_t testvfwmaccbf16_vv_f32m8(vfloat32m8_t vd, vbfloat16m4_t vs1, vbfloat16m4_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m8(vd,vs1,vs2,vl);}
vfloat32mf2_t testvfwmaccbf16_vf_f32mf2(vfloat32mf2_t vd, bfloat16_t vs1, vbfloat16mf4_t vs2, size_t vl){ return vfwmaccbf16_vf_f32mf2(vd,vs1,vs2,vl);}
vfloat32m1_t testvfwmaccbf16_vf_f32m1(vfloat32m1_t vd, bfloat16_t vs1, vbfloat16mf2_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m1(vd,vs1,vs2,vl);}
vfloat32m2_t testvfwmaccbf16_vf_f32m2(vfloat32m2_t vd, bfloat16_t vs1, vbfloat16m1_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m2(vd,vs1,vs2,vl);}
vfloat32m4_t testvfwmaccbf16_vf_f32m4(vfloat32m4_t vd, bfloat16_t vs1, vbfloat16m2_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m4(vd,vs1,vs2,vl);}
vfloat32m8_t testvfwmaccbf16_vf_f32m8(vfloat32m8_t vd, bfloat16_t vs1, vbfloat16m4_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m8(vd,vs1,vs2,vl);}
vfloat32mf2_t testvfwmaccbf16_vv_f32mf2_m(vbool64_t mask, vfloat32mf2_t vd, vbfloat16mf4_t vs1, vbfloat16mf4_t vs2, size_t vl){ return vfwmaccbf16_vv_f32mf2_m(mask,vd,vs1,vs2,vl);}
vfloat32m1_t testvfwmaccbf16_vv_f32m1_m(vbool32_t mask, vfloat32m1_t vd, vbfloat16mf2_t vs1, vbfloat16mf2_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m1_m(mask,vd,vs1,vs2,vl);}
vfloat32m2_t testvfwmaccbf16_vv_f32m2_m(vbool16_t mask, vfloat32m2_t vd, vbfloat16m1_t vs1, vbfloat16m1_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m2_m(mask,vd,vs1,vs2,vl);}
vfloat32m4_t testvfwmaccbf16_vv_f32m4_m(vbool8_t mask, vfloat32m4_t vd, vbfloat16m2_t vs1, vbfloat16m2_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m4_m(mask,vd,vs1,vs2,vl);}
vfloat32m8_t testvfwmaccbf16_vv_f32m8_m(vbool4_t mask, vfloat32m8_t vd, vbfloat16m4_t vs1, vbfloat16m4_t vs2, size_t vl){ return vfwmaccbf16_vv_f32m8_m(mask,vd,vs1,vs2,vl);}
vfloat32mf2_t testvfwmaccbf16_vf_f32mf2_m(vbool64_t mask, vfloat32mf2_t vd, bfloat16_t vs1, vbfloat16mf4_t vs2, size_t vl){ return vfwmaccbf16_vf_f32mf2_m(mask,vd,vs1,vs2,vl);}
vfloat32m1_t testvfwmaccbf16_vf_f32m1_m(vbool32_t mask, vfloat32m1_t vd, bfloat16_t vs1, vbfloat16mf2_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m1_m(mask,vd,vs1,vs2,vl);}
vfloat32m2_t testvfwmaccbf16_vf_f32m2_m(vbool16_t mask, vfloat32m2_t vd, bfloat16_t vs1, vbfloat16m1_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m2_m(mask,vd,vs1,vs2,vl);}
vfloat32m4_t testvfwmaccbf16_vf_f32m4_m(vbool8_t mask, vfloat32m4_t vd, bfloat16_t vs1, vbfloat16m2_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m4_m(mask,vd,vs1,vs2,vl);}
vfloat32m8_t testvfwmaccbf16_vf_f32m8_m(vbool4_t mask, vfloat32m8_t vd, bfloat16_t vs1, vbfloat16m4_t vs2, size_t vl){ return vfwmaccbf16_vf_f32m8_m(mask,vd,vs1,vs2,vl);}

/* { dg-final { scan-assembler-times "vfwmaccbf16.vv\t" 10 } } */
/* { dg-final { scan-assembler-times "vfwmaccbf16.vf\t" 10 } } */
