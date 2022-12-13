PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 0
POP [0]
PUSH [0]
PUSH 0
POP [7]
PUSH 1
POP [7]
PUSH [7]
PUSH 0
POP [8]
PUSH 5
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
jbe :label_0x55dbb01e90d0
:label_0x55dbb01e58d0
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
jmp :label_exit_if_0x55dbb01e8500
:label_0x55dbb01e90d0
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
jbe :label_0x55dbb01e59c0
:label_0x55dbb01e86e0
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
jbe :label_0x55dbb01e8d10
:label_0x55dbb01e8c80
PUSH 0
OUT
jmp :label_exit_if_0x55dbb01e8710
:label_0x55dbb01e8d10
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
jmp :label_exit_if_0x55dbb01e8710
:label_exit_if_0x55dbb01e8710
jmp :label_exit_if_0x55dbb01e9100
:label_0x55dbb01e59c0
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
jbe :label_0x55dbb01e97f0
:label_0x55dbb01e7d20
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
jmp :label_exit_if_0x55dbb01e80e0
:label_0x55dbb01e97f0
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x55dbb01e9d00
:label_0x55dbb01e9910
PUSH 2
OUT
PUSH [0]
SQRT
POP [0]
PUSH [0]
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
PUSH [0]
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
PUSH [0]
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
jmp :label_exit_if_0x55dbb01e9820
:label_0x55dbb01e9d00
PUSH 0
OUT
jmp :label_exit_if_0x55dbb01e9820
:label_exit_if_0x55dbb01e9820
jmp :label_exit_if_0x55dbb01e80e0
:label_exit_if_0x55dbb01e80e0
jmp :label_exit_if_0x55dbb01e9100
:label_exit_if_0x55dbb01e9100
jmp :label_exit_if_0x55dbb01e8500
:label_exit_if_0x55dbb01e8500
PUSH 0
PUSH rax
PUSH 3
SUB
POP rax
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
jbe :label_0x55dbb01e95e0
:label_0x55dbb01e94f0
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
jmp :label_exit_if_0x55dbb01e9400
:label_0x55dbb01e95e0
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
jmp :label_exit_if_0x55dbb01e9400
:label_exit_if_0x55dbb01e9400
PUSH 0
PUSH rax
PUSH 2
SUB
POP rax
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
jbe :label_0x55dbb01e5f00
:label_0x55dbb01e5e70
PUSH 993
OUT
jmp :label_exit_if_0x55dbb01e5d80
:label_0x55dbb01e5f00
PUSH 0
OUT
jmp :label_exit_if_0x55dbb01e5d80
:label_exit_if_0x55dbb01e5d80
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
