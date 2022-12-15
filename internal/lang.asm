PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 0
POP [0]
PUSH [0]
PUSH 0
POP [4]
PUSH 0
POP [4]
PUSH [4]
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
PUSH [4]
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
PUSH 4
ADD
POP rax
PUSH rax
PUSH 3
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 3
SUB
PUSH 4
ADD
POP rax
PUSH 42
POP [4]
PUSH [4]
PUSH 993
POP [4]
PUSH [4]
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x5581dbad3f20
:label_0x5581dbad3dd0
PUSH rax
PUSH 1
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 4
ADD
POP rax
PUSH rax
PUSH 2
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 4
ADD
POP rax
call :func_solve_linear
jmp :label_exit_if_0x5581dbad3ce0
:label_0x5581dbad3f20
PUSH rax
PUSH 1
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 4
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x5581dbad48e0
:label_0x5581dbad4040
PUSH rax
PUSH 2
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 4
ADD
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x5581dbad4280
:label_0x5581dbad4160
PUSH 1
OUT
PUSH 0
OUT
jmp :label_exit_if_0x5581dbad4070
:label_0x5581dbad4280
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
PUSH rax
PUSH 2
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 4
ADD
POP rax
MUL
PUSH 0
A
PUSH 0
jbe :label_0x5581dbad4490
:label_0x5581dbad4400
PUSH 0
OUT
jmp :label_exit_if_0x5581dbad42b0
:label_0x5581dbad4490
PUSH 2
OUT
PUSH -1
PUSH -1
PUSH rax
PUSH 2
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 4
ADD
POP rax
MUL
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
DIV
SQRT
MUL
OUT
PUSH -1
PUSH rax
PUSH 2
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 4
ADD
POP rax
MUL
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
DIV
SQRT
OUT
jmp :label_exit_if_0x5581dbad42b0
:label_exit_if_0x5581dbad42b0
jmp :label_exit_if_0x5581dbad4070
:label_exit_if_0x5581dbad4070
jmp :label_exit_if_0x5581dbad3f50
:label_0x5581dbad48e0
PUSH 0
POP [0]
PUSH rax
PUSH 1
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 4
ADD
POP rax
PUSH rax
PUSH 1
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 4
ADD
POP rax
MUL
PUSH 4
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
MUL
PUSH rax
PUSH 2
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 4
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
jbe :label_0x5581dbad4ee0
:label_0x5581dbad4ca0
PUSH 1
OUT
PUSH -1
PUSH rax
PUSH 1
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 4
ADD
POP rax
MUL
PUSH 2
DIV
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
MUL
OUT
jmp :label_exit_if_0x5581dbad4bb0
:label_0x5581dbad4ee0
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x5581dbad55d0
:label_0x5581dbad5000
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
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 4
ADD
POP rax
MUL
PUSH [0]
PUSH 2
DIV
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
MUL
ADD
OUT
PUSH -1
PUSH rax
PUSH 1
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 4
ADD
POP rax
MUL
PUSH [0]
PUSH 2
DIV
PUSH rax
PUSH 0
ADD
PUSH 4
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
PUSH 4
ADD
POP rax
MUL
SUB
OUT
jmp :label_exit_if_0x5581dbad4f10
:label_0x5581dbad55d0
PUSH 0
OUT
jmp :label_exit_if_0x5581dbad4f10
:label_exit_if_0x5581dbad4f10
jmp :label_exit_if_0x5581dbad4bb0
:label_exit_if_0x5581dbad4bb0
jmp :label_exit_if_0x5581dbad3f50
:label_exit_if_0x5581dbad3f50
jmp :label_exit_if_0x5581dbad3ce0
:label_exit_if_0x5581dbad3ce0
PUSH 0
PUSH rax
PUSH 4
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
jbe :label_0x5581dbad5a50
:label_0x5581dbad5960
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
jmp :label_exit_if_0x5581dbad5870
:label_0x5581dbad5a50
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
MUL
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
OUT
jmp :label_exit_if_0x5581dbad5870
:label_exit_if_0x5581dbad5870
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
jbe :label_0x5581dbad5f60
:label_0x5581dbad5ed0
PUSH 993
OUT
jmp :label_exit_if_0x5581dbad5de0
:label_0x5581dbad5f60
PUSH 0
OUT
jmp :label_exit_if_0x5581dbad5de0
:label_exit_if_0x5581dbad5de0
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
