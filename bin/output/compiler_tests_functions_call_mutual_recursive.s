.text
.globl f

r2:
r1:
add x6, zero, a1
li x7, 0
sub x5, x6, x7
seqz x5, x5
addi x6, zero, 0
addi x7, zero, 0
beq x5, zero, _else_block_2
li x6, 1
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_1
_else_block_2:
add x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_1
_end_of_ifelse_1:
addi x5, zero, 0
