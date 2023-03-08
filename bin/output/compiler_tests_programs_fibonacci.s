.text
.globl f

fib:
add x6, zero, a1
li x7, 0
sgt x5, x6, x7
xori x5, x5, 1
addi x6, zero, 0
addi x7, zero, 0
beq x5, zero, _else_block_2
li x6, 0
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_1
_else_block_2:
beq zero, zero, _end_of_ifelse_1
_end_of_ifelse_1:
addi x5, zero, 0
add x6, zero, a1
li x7, 1
sub x5, x6, x7
seqz x5, x5
addi x6, zero, 0
addi x7, zero, 0
beq x5, zero, _else_block_4
li x6, 1
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_3
_else_block_4:
beq zero, zero, _end_of_ifelse_3
_end_of_ifelse_3:
addi x5, zero, 0
add x5, x6, x7
addi x6, zero, 0
addi x7, zero, 0
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
