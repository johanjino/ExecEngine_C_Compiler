.text
.globl f

f:
li x5, 0
_start_for_1:
add x7, zero, x5
li x28, 0
slt x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
beq x6, zero, _end_for_2
li x7, 1
mv a0, x7
addi x7, zero, 0
mv a0, a0
ret
beq zero, zero, _start_for_1
_end_for_2:
addi x6, zero, 0
li x6, 19937
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
