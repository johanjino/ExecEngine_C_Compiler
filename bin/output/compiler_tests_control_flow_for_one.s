.text
.globl f

f:
li x5, 0
_start_for_1:
add x7, zero, x5
li x28, 1
slt x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
beq x6, zero, _end_for_2
add x7, zero, x5
li x28, 1
add x5, x7, x28
addi x7, zero, 0
addi x28, zero, 0
beq zero, zero, _start_for_1
_end_for_2:
addi x6, zero, 0
add x7, zero, x5
li x28, 19937
add x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
