.text
.globl f

f:
add x7, zero, a1
add x28, zero, a2
mul x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
add x7, zero, a3
add x5, x6, x7
addi x6, zero, 0
addi x7, zero, 0
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
