.text
.globl f

f:
li x5, 1
beq x5, zero, _else_block_2
li x6, 11
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_1
_else_block_2:
beq zero, zero, _end_of_ifelse_1
_end_of_ifelse_1:
addi x5, zero, 0
li x5, 10
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
