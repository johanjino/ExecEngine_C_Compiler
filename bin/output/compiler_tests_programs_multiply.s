.text
.globl f

multiply:
li x5, 0
add x7, zero, a1
li x28, 0
slt x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
beq x6, zero, _else_block_2
mv a0, x7
addi x7, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_1
_else_block_2:
beq zero, zero, _end_of_ifelse_1
_end_of_ifelse_1:
addi x6, zero, 0
_start_while_3:
add x7, zero, a1
li x28, 0
sgt x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
beq x6, zero, _end_while_4
beq zero, zero, _start_while_3
_end_while_4:
addi x6, zero, 0
add x6, zero, x5
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
