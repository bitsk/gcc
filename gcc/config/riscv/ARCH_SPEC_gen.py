#!/usr/bin/env python3

import sys
import subprocess
from itertools import groupby

outputs = []
inputs = []

cmd="./multilib-generator \
rv64ima_c-lp64--c*p_zpn_zprvsfextra_zpsfoperand*zba_zbb_zbc_zbs*v*zfh*zihintpause,c*v0p7*zfh \
rv64ima_c_xtheadc-lp64--c*p_zpn_zprvsfextra_zpsfoperand*zba_zbb_zbc_zbs*v*zfh*zicbom_zicboz*zihintntl_zihintpause_zawrs*svinval_svpbmt,c*v0p7*zfh \
rv64imafd_c-lp64d--p_zpn_zprvsfextra_zpsfoperand*zba_zbb_zbc_zbs*v*zihintpause,v0p7 \
rv64imafd_zfh_c_xtheadc-lp64d--p_zpn_zprvsfextra_zpsfoperand*zba_zbb_zbc_zbs*zfh*zicbom_zicboz*zihintntl_zihintpause_zawrs*zfa**zicond*zfbfmin*zca_zcb_zcd_zcf*zvfbfmin_zvfbfwma*svinval_svpbmt \
rv64imafdv_zfh_c_xtheadc-lp64d--p_zpn_zprvsfextra_zpsfoperand*zba_zbb_zbc_zbs*xtheadvdot*zihintntl_zihintpause_zawrs*zfa*svinval_svpbmt*xtheadmatrix*zicbom_zicboz*zicond*zfbfmin*zca_zcb_zcd_zcf*zvfbfmin_zvfbfwma \
rv64imafd_v0p7_zfh_c_xtheadc-lp64d-- \
rv32ima_c_xtheadc-ilp32--zicbom_zicboz*zihintntl_zihintpause_zawrs*svinval_svpbmt \
rv32imafd_c-ilp32d--p_zpn_zprvsfextra_zpsfoperand*zba_zbb_zbc_zbs*zihintpause*zfh \
rv32imafd_zfh_c_xtheadc-ilp32d--p_zpn_zprvsfextra_zpsfoperand*zba_zbb_zbc_zbs*zicbom_zicboz*zihintntl_zihintpause_zawrs*zfa*svinval_svpbmt \
rv32imafdv_zfh_c_xtheadc-ilp32d--p_zpn_zpsfoperand*zba_zbb_zbc_zbs*xtheadvdot*zicbom_zicboz*zihintntl_zihintpause_zawrs*zfa*svinval_svpbmt*xtheadmatrix"

ret = subprocess.getoutput(cmd)
# print(ret)

start = False
with open("t-linux-multilib", "r", encoding="utf-8") as ofp:
    while True:
        tl = ofp.readline()
        if tl.startswith("MULTILIB_DIRNAMES"):
            start = True
        if not start:
            continue
        inputs += tl.split()
        if not tl.endswith("\\\n"):
            break

start=ret.find('MULTILIB_DIRNAMES')
end=ret.find('MULTILIB_REQUIRED')
ret=ret[start:end:1]
# print(ret)

inputs = ret.split()
inputs = filter(lambda x: x.startswith("rv"), inputs)
inputs = list(sorted(list(set(inputs))))

def findir(arch):
    if "xthead" in arch and "v0p7" in arch:
        return "v0p7_xthead"
    if "xthead" in arch and "v" in "".join(filter(lambda x: not (x.startswith("z" or x.startswith("x"))), arch.split("_"))).lstrip("rv"):
        return "v_xthead"
    if "xthead" in arch:
        return "xthead"
    return False


# print("#define ARCH_SPEC \\")
for arch in inputs:
    dir = findir(arch)
    if not dir:
        continue
    print("  \"%{march=" + arch + ":" + dir + "}\" \\")

print("")