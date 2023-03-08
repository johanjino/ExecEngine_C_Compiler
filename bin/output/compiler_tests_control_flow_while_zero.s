.text
.globl f

f:
_start_while_1:
li x5, 0
beq x5, zero, _end_while_2
beq zero, zero, _start_while_1
_end_while_2:
addi x5, zero, 0
li x5, 19937
mv a0, x5
addi x5, zero, 0
mv a0, a0
ret
