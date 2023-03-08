.text
.globl f

bsqrt:
_start_while_1:
add x6, zero, a1
li x28, 1
add x29, zero, a2
slt x7, x28, x29
addi x28, zero, 0
addi x29, zero, 0
add x5, x6, x7
addi x6, zero, 0
addi x7, zero, 0
beq x5, zero, _end_while_2
add x28, zero, x6
add x29, zero, x6
mul x7, x28, x29
addi x28, zero, 0
addi x29, zero, 0
add x29, zero, x7
add x30, zero, a3
sgt x28, x29, x30
xori x28, x28, 1
addi x29, zero, 0
addi x30, zero, 0
beq x28, zero, _else_block_4
add a1, zero, x6
beq zero, zero, _end_of_ifelse_3
_else_block_4:
add a2, zero, x6
beq zero, zero, _end_of_ifelse_3
_end_of_ifelse_3:
addi x28, zero, 0
beq zero, zero, _start_while_1
_end_while_2:
addi x5, zero, 0
add x29, zero, a1
add x30, zero, a1
mul x28, x29, x30
addi x29, zero, 0
addi x30, zero, 0
add x29, zero, a3
slt x5, x28, x29
addi x28, zero, 0
addi x29, zero, 0
beq x5, zero, _else_block_6
add x28, zero, a2
mv a0, x28
addi x28, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_5
_else_block_6:
add x28, zero, a1
mv a0, x28
addi x28, zero, 0
mv a0, a0
ret
beq zero, zero, _end_of_ifelse_5
_end_of_ifelse_5:
addi x5, zero, 0
