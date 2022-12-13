PUSH 666
POP rax
PUSH 0
POP [7]
PUSH 0
POP [7]
PUSH [7]
PUSH 0
POP [8]
PUSH 0
POP [8]
PUSH [8]
PUSH 0
POP [9]
PUSH 1
POP [9]
PUSH [9]
PUSH [7]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH [8]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH [9]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
call :func_solve_square
HLT
:func_solve_square
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
jbe :label_0x558f63ecb7d0
:label_0x558f63ec8a80
PUSH rax
PUSH 1
ADD
PUSH 3
SUB
PUSH 0
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 3
ADD
PUSH 0
ADD
POP rax
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH rax
PUSH 2
ADD
PUSH 3
SUB
PUSH 1
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
PUSH 3
ADD
PUSH 1
ADD
POP rax
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
call :func_solve_linear
jmp :label_exit_if_0x558f63ecbf50
:label_0x558f63ecb7d0
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
jbe :label_0x558f63ec8810
:label_0x558f63ecb530
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
jbe :label_0x558f63ecbb60
:label_0x558f63ecb920
PUSH 0
OUT
jmp :label_exit_if_0x558f63ecb560
:label_0x558f63ecbb60
PUSH 2
OUT
PUSH 0
PUSH 0
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
SUB
SQRT
SUB
OUT
PUSH 0
PUSH 0
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
SUB
SQRT
ADD
OUT
jmp :label_exit_if_0x558f63ecb560
:label_exit_if_0x558f63ecb560
jmp :label_exit_if_0x558f63ecb800
:label_0x558f63ec8810
PUSH 0
POP [3]
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
POP [3]
PUSH [3]
PUSH [3]
PUSH 0
E
PUSH 0
jbe :label_0x558f63ecb0b0
:label_0x558f63ecc640
PUSH 1
OUT
PUSH 0
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
SUB
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
jmp :label_exit_if_0x558f63ecaf30
:label_0x558f63ecb0b0
PUSH [3]
PUSH 0
A
PUSH 0
jbe :label_0x558f63ecc1f0
:label_0x558f63ecb1d0
PUSH 2
OUT
PUSH [3]
SQRT
POP [3]
PUSH [3]
PUSH 0
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
SUB
PUSH [3]
ADD
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
PUSH 0
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
SUB
PUSH [3]
SUB
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
jmp :label_exit_if_0x558f63ecb0e0
:label_0x558f63ecc1f0
PUSH 0
OUT
jmp :label_exit_if_0x558f63ecb0e0
:label_exit_if_0x558f63ecb0e0
jmp :label_exit_if_0x558f63ecaf30
:label_exit_if_0x558f63ecaf30
jmp :label_exit_if_0x558f63ecb800
:label_exit_if_0x558f63ecb800
jmp :label_exit_if_0x558f63ecbf50
:label_exit_if_0x558f63ecbf50
PUSH 0
PUSH rax
OUT
PUSH rax
PUSH 3
SUB
POP rax
PUSH rax
OUT
RET
:func_solve_linear
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
jbe :label_0x558f63ec8ba0
:label_0x558f63ecc580
PUSH rax
PUSH 1
ADD
PUSH 2
SUB
PUSH 0
SUB
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
PUSH 2
ADD
PUSH 0
ADD
POP rax
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
call :func_solve_const
jmp :label_exit_if_0x558f63ecc490
:label_0x558f63ec8ba0
PUSH 1
OUT
PUSH 0
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
SUB
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
jmp :label_exit_if_0x558f63ecc490
:label_exit_if_0x558f63ecc490
PUSH 0
PUSH rax
OUT
PUSH rax
PUSH 2
SUB
POP rax
PUSH rax
OUT
RET
:func_solve_const
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
jbe :label_0x558f63ec90b0
:label_0x558f63ec9020
PUSH 993
OUT
jmp :label_exit_if_0x558f63ec8f30
:label_0x558f63ec90b0
PUSH 0
OUT
jmp :label_exit_if_0x558f63ec8f30
:label_exit_if_0x558f63ec8f30
PUSH 0
PUSH rax
OUT
PUSH rax
PUSH 1
SUB
POP rax
PUSH rax
OUT
RET
