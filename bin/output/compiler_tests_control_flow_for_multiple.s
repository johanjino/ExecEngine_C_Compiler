.text
.globl f

f:
li x6, 0
li x5, 0
_start_for_1:
add x28, zero, x5
li x29, 10
slt x7, x28, x29
addi x28, zero, 0
addi x29, zero, 0
beq x7, zero, _end_for_2
add x28, zero, x6
li x29, 1
sub x6, x28, x29
addi x28, zero, 0
addi x29, zero, 0
add x28, zero, x5
li x29, 1
add x5, x28, x29
addi x28, zero, 0
addi x29, zero, 0
beq zero, zero, _start_for_1
_end_for_2:
addi x7, zero, 0
add x7, zero, x6
mv a0, x7
addi x7, zero, 0
mv a0, a0
ret
