.text
.globl f

f:
add x6, zero, a1
add x7, zero, a2
sgt x5, x6, x7
xori x5, x5, 1
addi x6, zero, 0
addi x7, zero, 0
add x6, zero, x5
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
