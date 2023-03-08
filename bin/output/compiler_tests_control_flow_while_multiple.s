.text
.globl f

f:
li x5, 20
_start_while_1:
add x7, zero, x5
li x28, 10
sgt x6, x7, x28
addi x7, zero, 0
addi x28, zero, 0
beq x6, zero, _end_while_2
add x7, zero, x5
li x28, 1
sub x5, x7, x28
addi x7, zero, 0
addi x28, zero, 0
beq zero, zero, _start_while_1
_end_while_2:
addi x6, zero, 0
add x6, zero, x5
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
