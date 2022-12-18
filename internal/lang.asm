PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 100
POP [0]
PUSH [0]
PUSH 0
POP [4]
PUSH 0
POP [4]
PUSH [4]
PUSH 0
POP [5]
PUSH 2
POP [5]
PUSH [5]
PUSH 0
POP [6]
PUSH 9
POP [6]
PUSH [6]
PUSH [4]
PUSH [5]
PUSH [6]
call :func_solve_square
PUSH 125
OUT
HLT
:func_solve_square
PUSH rax
PUSH 2
ADD
PUSH 0
SUB
POP rax
POP [rax]
PUSH rax
PUSH 2
SUB
PUSH 0
ADD
POP rax
PUSH rax
PUSH 2
ADD
PUSH 1
SUB
POP rax
POP [rax]
PUSH rax
PUSH 2
SUB
PUSH 1
ADD
POP rax
PUSH rax
PUSH 2
ADD
PUSH 2
SUB
POP rax
POP [rax]
PUSH rax
PUSH 2
SUB
PUSH 2
ADD
POP rax
PUSH rax
PUSH 5
ADD
POP rax
PUSH 0
POP [4]
PUSH 42
POP [4]
PUSH [4]
PUSH 993
POP [4]
PUSH [4]
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55575cc7d600
:label_0x55575cc7d4b0
PUSH rax
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 4
ADD
POP rax
PUSH rax
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 3
ADD
POP rax
call :func_solve_linear
jmp :label_exit_if_0x55575cc7d3c0
:label_0x55575cc7d600
PUSH rax
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 4
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55575cc7e050
:label_0x55575cc7d720
PUSH rax
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 3
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55575cc7d960
:label_0x55575cc7d840
PUSH 1
OUT
PUSH 0
OUT
jmp :label_exit_if_0x55575cc7d750
:label_0x55575cc7d960
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
PUSH rax
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 3
ADD
POP rax
MUL
PUSH 0
A
PUSH 0
jbe :label_0x55575cc7db70
:label_0x55575cc7dae0
PUSH 0
OUT
jmp :label_exit_if_0x55575cc7d990
:label_0x55575cc7db70
PUSH 2
OUT
PUSH -1
PUSH -1
PUSH rax
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 3
ADD
POP rax
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
DIV
MUL
SQRT
MUL
OUT
PUSH -1
PUSH rax
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 3
ADD
POP rax
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
DIV
MUL
SQRT
OUT
jmp :label_exit_if_0x55575cc7d990
:label_exit_if_0x55575cc7d990
jmp :label_exit_if_0x55575cc7d750
:label_exit_if_0x55575cc7d750
jmp :label_exit_if_0x55575cc7d630
:label_0x55575cc7e050
PUSH 0
POP [0]
PUSH rax
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 4
ADD
POP rax
PUSH rax
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 4
ADD
POP rax
MUL
PUSH 4
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
MUL
PUSH rax
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 3
ADD
POP rax
MUL
SUB
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
E
PUSH 0
jbe :label_0x55575cc7e680
:label_0x55575cc7e410
PUSH 1
OUT
PUSH -1
PUSH rax
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 4
ADD
POP rax
PUSH 2
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
MUL
DIV
MUL
OUT
jmp :label_exit_if_0x55575cc7e320
:label_0x55575cc7e680
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x55575cc7edd0
:label_0x55575cc7e7a0
PUSH 2
OUT
PUSH [0]
SQRT
POP [0]
PUSH [0]
PUSH -1
PUSH rax
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 4
ADD
POP rax
PUSH [0]
ADD
MUL
PUSH 2
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
MUL
DIV
OUT
PUSH -1
PUSH rax
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 4
ADD
POP rax
PUSH [0]
SUB
MUL
PUSH 2
PUSH rax
PUSH 5
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 5
ADD
POP rax
MUL
DIV
OUT
jmp :label_exit_if_0x55575cc7e6b0
:label_0x55575cc7edd0
PUSH 0
OUT
jmp :label_exit_if_0x55575cc7e6b0
:label_exit_if_0x55575cc7e6b0
jmp :label_exit_if_0x55575cc7e320
:label_exit_if_0x55575cc7e320
jmp :label_exit_if_0x55575cc7d630
:label_exit_if_0x55575cc7d630
jmp :label_exit_if_0x55575cc7d3c0
:label_exit_if_0x55575cc7d3c0
PUSH 0
PUSH rax
PUSH 5
SUB
POP rax
RET
:func_solve_linear
PUSH rax
PUSH 1
ADD
PUSH 0
SUB
POP rax
POP [rax]
PUSH rax
PUSH 1
SUB
PUSH 0
ADD
POP rax
PUSH rax
PUSH 1
ADD
PUSH 1
SUB
POP rax
POP [rax]
PUSH rax
PUSH 1
SUB
PUSH 1
ADD
POP rax
PUSH rax
PUSH 2
ADD
POP rax
PUSH rax
PUSH 2
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55575cc7f250
:label_0x55575cc7f160
PUSH rax
PUSH 1
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
ADD
POP rax
call :func_solve_const_equal_zero
jmp :label_exit_if_0x55575cc7f070
:label_0x55575cc7f250
PUSH 1
OUT
PUSH -1
PUSH rax
PUSH 1
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH rax
PUSH 2
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
ADD
POP rax
DIV
MUL
OUT
jmp :label_exit_if_0x55575cc7f070
:label_exit_if_0x55575cc7f070
PUSH 0
PUSH rax
PUSH 2
SUB
POP rax
RET
:func_solve_const_equal_zero
PUSH rax
PUSH 0
ADD
PUSH 0
SUB
POP rax
POP [rax]
PUSH rax
PUSH 0
SUB
PUSH 0
ADD
POP rax
PUSH rax
PUSH 1
ADD
POP rax
PUSH rax
PUSH 1
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55575cc7f790
:label_0x55575cc7f700
PUSH 993
OUT
jmp :label_exit_if_0x55575cc7f610
:label_0x55575cc7f790
PUSH 0
OUT
jmp :label_exit_if_0x55575cc7f610
:label_exit_if_0x55575cc7f610
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
