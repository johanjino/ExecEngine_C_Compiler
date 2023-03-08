.text
.globl f

g:
add x5, zero, a1
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
f:
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
