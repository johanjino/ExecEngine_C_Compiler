.text
.globl f

f:
li x5, 1
add x6, zero, x5
add x7, zero, x5
add x5, x6, x7
addi x6, zero, 0
addi x7, zero, 0
add x6, zero, x5
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
