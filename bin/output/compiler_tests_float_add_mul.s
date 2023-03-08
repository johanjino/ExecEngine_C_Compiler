.text
.globl f

f:
add x6, zero, a1
add x28, zero, a2
add x29, zero, a3
mul x7, x28, x29
addi x28, zero, 0
addi x29, zero, 0
add x5, x6, x7
addi x6, zero, 0
addi x7, zero, 0
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
