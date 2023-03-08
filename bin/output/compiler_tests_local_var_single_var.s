.text
.globl f

f:
li x5, 1234
add x6, zero, x5
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
