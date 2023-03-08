.text
.globl f

f:
li x5, 1234
add x6, zero, x5
add x7, zero, x6
mv a0, x7
addi x7, zero, 0
mv a0, a0
ret
