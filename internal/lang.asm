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
jbe :label_0x555bb4d394e0
:label_0x555bb4d39390
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
jmp :label_exit_if_0x555bb4d392a0
:label_0x555bb4d394e0
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
jbe :label_0x555bb4d39f30
:label_0x555bb4d39600
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
jbe :label_0x555bb4d39840
:label_0x555bb4d39720
PUSH 1
OUT
PUSH 0
OUT
jmp :label_exit_if_0x555bb4d39630
:label_0x555bb4d39840
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
jbe :label_0x555bb4d39a50
:label_0x555bb4d399c0
PUSH 0
OUT
jmp :label_exit_if_0x555bb4d39870
:label_0x555bb4d39a50
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
jmp :label_exit_if_0x555bb4d39870
:label_exit_if_0x555bb4d39870
jmp :label_exit_if_0x555bb4d39630
:label_exit_if_0x555bb4d39630
jmp :label_exit_if_0x555bb4d39510
:label_0x555bb4d39f30
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
jbe :label_0x555bb4d3a560
:label_0x555bb4d3a2f0
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
jmp :label_exit_if_0x555bb4d3a200
:label_0x555bb4d3a560
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x555bb4d3acb0
:label_0x555bb4d3a680
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
jmp :label_exit_if_0x555bb4d3a590
:label_0x555bb4d3acb0
PUSH 0
OUT
jmp :label_exit_if_0x555bb4d3a590
:label_exit_if_0x555bb4d3a590
jmp :label_exit_if_0x555bb4d3a200
:label_exit_if_0x555bb4d3a200
jmp :label_exit_if_0x555bb4d39510
:label_exit_if_0x555bb4d39510
jmp :label_exit_if_0x555bb4d392a0
:label_exit_if_0x555bb4d392a0
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
jbe :label_0x555bb4d3b130
:label_0x555bb4d3b040
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
jmp :label_exit_if_0x555bb4d3af50
:label_0x555bb4d3b130
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
jmp :label_exit_if_0x555bb4d3af50
:label_exit_if_0x555bb4d3af50
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
jbe :label_0x555bb4d3b670
:label_0x555bb4d3b5e0
PUSH 993
OUT
jmp :label_exit_if_0x555bb4d3b4f0
:label_0x555bb4d3b670
PUSH 0
OUT
jmp :label_exit_if_0x555bb4d3b4f0
:label_exit_if_0x555bb4d3b4f0
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
