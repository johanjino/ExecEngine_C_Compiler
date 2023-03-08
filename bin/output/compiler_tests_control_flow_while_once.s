.text
.globl f

f:
li x5, 1
_start_while_1:
add x6, zero, x5
beq x6, zero, _end_while_2
li x5, 0
beq zero, zero, _start_while_1
_end_while_2:
addi x6, zero, 0
li x6, 19937
mv a0, x6
addi x6, zero, 0
mv a0, a0
ret
