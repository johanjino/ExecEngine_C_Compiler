.text
.globl f

f:
add x6, zero, a1
add x7, zero, a2
add x5, x6, x7
addi x6, zero, 0
addi x7, zero, 0
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
