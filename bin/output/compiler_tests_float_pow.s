.text
.globl f

f:
li x5, 1
li x6, 0
_start_while_1:
add x28, zero, x6
add x29, zero, a2
slt x7, x28, x29
addi x28, zero, 0
addi x29, zero, 0
beq x7, zero, _end_while_2
add x28, zero, x5
add x29, zero, a1
mul x5, x28, x29
addi x28, zero, 0
addi x29, zero, 0
beq zero, zero, _start_while_1
_end_while_2:
addi x7, zero, 0
add x7, zero, x5
mv a0, x7
addi x7, zero, 0
mv a0, a0
ret
