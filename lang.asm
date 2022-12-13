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
jbe :label_0x55e94fc1a0b0
:label_0x55e94fc168d0
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
jmp :label_exit_if_0x55e94fc194e0
:label_0x55e94fc1a0b0
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
jbe :label_0x55e94fc169c0
:label_0x55e94fc196c0
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
jbe :label_0x55e94fc19cf0
:label_0x55e94fc19c60
PUSH 0
OUT
jmp :label_exit_if_0x55e94fc196f0
:label_0x55e94fc19cf0
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
jmp :label_exit_if_0x55e94fc196f0
:label_exit_if_0x55e94fc196f0
jmp :label_exit_if_0x55e94fc1a0e0
:label_0x55e94fc169c0
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
jbe :label_0x55e94fc1a7d0
:label_0x55e94fc18d00
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
jmp :label_exit_if_0x55e94fc190c0
:label_0x55e94fc1a7d0
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x55e94fc1ace0
:label_0x55e94fc1a8f0
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
jmp :label_exit_if_0x55e94fc1a800
:label_0x55e94fc1ace0
PUSH 0
OUT
jmp :label_exit_if_0x55e94fc1a800
:label_exit_if_0x55e94fc1a800
jmp :label_exit_if_0x55e94fc190c0
:label_exit_if_0x55e94fc190c0
jmp :label_exit_if_0x55e94fc1a0e0
:label_exit_if_0x55e94fc1a0e0
jmp :label_exit_if_0x55e94fc194e0
:label_exit_if_0x55e94fc194e0
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
jbe :label_0x55e94fc1a5c0
:label_0x55e94fc1a4d0
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
jmp :label_exit_if_0x55e94fc1a3e0
:label_0x55e94fc1a5c0
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
jmp :label_exit_if_0x55e94fc1a3e0
:label_exit_if_0x55e94fc1a3e0
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
jbe :label_0x55e94fc16f00
:label_0x55e94fc16e70
PUSH 993
OUT
jmp :label_exit_if_0x55e94fc16d80
:label_0x55e94fc16f00
PUSH 0
OUT
jmp :label_exit_if_0x55e94fc16d80
:label_exit_if_0x55e94fc16d80
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
