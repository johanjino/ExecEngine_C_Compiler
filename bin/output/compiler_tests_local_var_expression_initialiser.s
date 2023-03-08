.text
.globl f

f:
li x5, 10
li x7, 20
add x28, zero, x5
add x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
add x7, zero, x6
mv a0, x7
addi x7, zero, 0
mv a0, a0
ret
