PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 0
POP [0]
PUSH [0]
PUSH 0
POP [7]
PUSH 0
POP [7]
PUSH [7]
PUSH 0
POP [8]
PUSH 2
POP [8]
PUSH [8]
PUSH 0
POP [9]
PUSH 9
POP [9]
PUSH [9]
PUSH [7]
PUSH [8]
PUSH [9]
call :func_solve_square
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
PUSH 3
ADD
POP rax
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c1a19f5960
:label_0x55c1a19f8800
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
POP rax
PUSH rax
PUSH 2
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 3
ADD
POP rax
call :func_solve_linear
jmp :label_exit_if_0x55c1a19f8c20
:label_0x55c1a19f5960
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c1a19f8e90
:label_0x55c1a19f5b40
PUSH rax
PUSH 2
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 3
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c1a19f9190
:label_0x55c1a19f8980
PUSH 1
OUT
PUSH 0
OUT
jmp :label_exit_if_0x55c1a19f9af0
:label_0x55c1a19f9190
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
PUSH rax
PUSH 2
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 3
ADD
POP rax
MUL
PUSH 0
A
PUSH 0
jbe :label_0x55c1a19f9010
:label_0x55c1a19f8f80
PUSH 0
OUT
jmp :label_exit_if_0x55c1a19f91c0
:label_0x55c1a19f9010
PUSH 2
OUT
PUSH -1
PUSH -1
PUSH rax
PUSH 2
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 3
ADD
POP rax
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
DIV
MUL
SQRT
MUL
OUT
PUSH -1
PUSH rax
PUSH 2
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 3
ADD
POP rax
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
DIV
MUL
SQRT
OUT
jmp :label_exit_if_0x55c1a19f91c0
:label_exit_if_0x55c1a19f91c0
jmp :label_exit_if_0x55c1a19f9af0
:label_exit_if_0x55c1a19f9af0
jmp :label_exit_if_0x55c1a19f5990
:label_0x55c1a19f8e90
PUSH 0
POP [0]
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
POP rax
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
POP rax
MUL
PUSH 4
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
MUL
PUSH rax
PUSH 2
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
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
jbe :label_0x55c1a19f7f00
:label_0x55c1a19f7e10
PUSH 1
OUT
PUSH -1
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
POP rax
PUSH 2
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
MUL
DIV
MUL
OUT
jmp :label_exit_if_0x55c1a19f7d20
:label_0x55c1a19f7f00
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x55c1a19fa000
:label_0x55c1a19f8020
PUSH 2
OUT
PUSH [0]
SQRT
POP [0]
PUSH [0]
PUSH -1
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
POP rax
PUSH [0]
ADD
MUL
PUSH 2
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
MUL
DIV
OUT
PUSH -1
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
POP rax
PUSH [0]
SUB
MUL
PUSH 2
PUSH rax
PUSH 0
ADD
PUSH 3
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 3
ADD
POP rax
MUL
DIV
OUT
jmp :label_exit_if_0x55c1a19f7f30
:label_0x55c1a19fa000
PUSH 0
OUT
jmp :label_exit_if_0x55c1a19f7f30
:label_exit_if_0x55c1a19f7f30
jmp :label_exit_if_0x55c1a19f7d20
:label_exit_if_0x55c1a19f7d20
jmp :label_exit_if_0x55c1a19f5990
:label_exit_if_0x55c1a19f5990
jmp :label_exit_if_0x55c1a19f8c20
:label_exit_if_0x55c1a19f8c20
PUSH 0
PUSH rax
PUSH 3
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
PUSH 0
ADD
PUSH 2
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 2
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c1a19f9880
:label_0x55c1a19f9790
PUSH rax
PUSH 1
ADD
PUSH 2
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 2
ADD
POP rax
call :func_solve_const_equal_zero
jmp :label_exit_if_0x55c1a19f96a0
:label_0x55c1a19f9880
PUSH 1
OUT
PUSH -1
PUSH rax
PUSH 1
ADD
PUSH 2
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 2
ADD
POP rax
PUSH rax
PUSH 0
ADD
PUSH 2
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 2
ADD
POP rax
DIV
MUL
OUT
jmp :label_exit_if_0x55c1a19f96a0
:label_exit_if_0x55c1a19f96a0
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
PUSH 0
ADD
PUSH 1
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 1
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c1a19fa450
:label_0x55c1a19fa3c0
PUSH 993
OUT
jmp :label_exit_if_0x55c1a19fa2d0
:label_0x55c1a19fa450
PUSH 0
OUT
jmp :label_exit_if_0x55c1a19fa2d0
:label_exit_if_0x55c1a19fa2d0
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
