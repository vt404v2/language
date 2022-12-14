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
PUSH 9
POP [8]
PUSH [8]
PUSH 0
POP [9]
PUSH 2
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
jbe :label_0x5582dafa3020
:label_0x5582dafa3c20
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
jmp :label_exit_if_0x5582dafa5c30
:label_0x5582dafa3020
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
jbe :label_0x5582dafa4220
:label_0x5582dafa2f00
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
jbe :label_0x5582dafa4520
:label_0x5582dafa4f70
PUSH 1
OUT
PUSH 0
OUT
jmp :label_exit_if_0x5582dafa2f30
:label_0x5582dafa4520
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
jbe :label_0x5582dafa43a0
:label_0x5582dafa4880
PUSH 0
OUT
jmp :label_exit_if_0x5582dafa4550
:label_0x5582dafa43a0
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
jmp :label_exit_if_0x5582dafa4550
:label_exit_if_0x5582dafa4550
jmp :label_exit_if_0x5582dafa2f30
:label_exit_if_0x5582dafa2f30
jmp :label_exit_if_0x5582dafa2d50
:label_0x5582dafa4220
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
jbe :label_0x5582dafa3770
:label_0x5582dafa31a0
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
jmp :label_exit_if_0x5582dafa30b0
:label_0x5582dafa3770
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x5582dafa5390
:label_0x5582dafa33b0
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
jmp :label_exit_if_0x5582dafa32c0
:label_0x5582dafa5390
PUSH 0
OUT
jmp :label_exit_if_0x5582dafa32c0
:label_exit_if_0x5582dafa32c0
jmp :label_exit_if_0x5582dafa30b0
:label_exit_if_0x5582dafa30b0
jmp :label_exit_if_0x5582dafa2d50
:label_exit_if_0x5582dafa2d50
jmp :label_exit_if_0x5582dafa5c30
:label_exit_if_0x5582dafa5c30
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
jbe :label_0x5582dafa4c10
:label_0x5582dafa4b20
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
jmp :label_exit_if_0x5582dafa4a30
:label_0x5582dafa4c10
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
jmp :label_exit_if_0x5582dafa4a30
:label_exit_if_0x5582dafa4a30
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
jbe :label_0x5582dafa57e0
:label_0x5582dafa5750
PUSH 993
OUT
jmp :label_exit_if_0x5582dafa5660
:label_0x5582dafa57e0
PUSH 0
OUT
jmp :label_exit_if_0x5582dafa5660
:label_exit_if_0x5582dafa5660
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
