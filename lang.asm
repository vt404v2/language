PUSH 666
POP rax
PUSH 0
POP [4]
PUSH 1
POP [4]
PUSH [4]
PUSH 0
POP [5]
PUSH 6
POP [5]
PUSH [5]
PUSH 0
POP [6]
PUSH 5
POP [6]
PUSH [6]
PUSH [4]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH [5]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH [6]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH rax
PUSH 3
SUB
POP rax
call :func_solve_square
HLT
:func_solve_square
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c9aa78dde0
:label_0x55c9aa78b870
PUSH rax
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c9aa78e4a0
:label_0x55c9aa78cf40
PUSH rax
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c9aa78e200
:label_0x55c9aa78dcc0
PUSH 993
OUT
jmp :label_exit_if_0x55c9aa78d870
:label_0x55c9aa78e200
PUSH 0
OUT
jmp :label_exit_if_0x55c9aa78d870
:label_exit_if_0x55c9aa78d870
jmp :label_exit_if_0x55c9aa78b8d0
:label_0x55c9aa78e4a0
PUSH 1
OUT
PUSH 0
PUSH [8]
SUB
PUSH [9]
DIV
OUT
jmp :label_exit_if_0x55c9aa78b8d0
:label_exit_if_0x55c9aa78b8d0
jmp :label_exit_if_0x55c9aa78e140
:label_0x55c9aa78dde0
PUSH rax
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
PUSH 0
E
PUSH 0
jbe :label_0x55c9aa78d450
:label_0x55c9aa78e0b0
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
PUSH rax
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
MUL
PUSH 0
A
PUSH 0
jbe :label_0x55c9aa78ce20
:label_0x55c9aa78cd90
PUSH 0
OUT
jmp :label_exit_if_0x55c9aa78e260
:label_0x55c9aa78ce20
PUSH 2
OUT
PUSH 0
PUSH 0
PUSH rax
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
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
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
DIV
SUB
SQRT
ADD
OUT
jmp :label_exit_if_0x55c9aa78e260
:label_exit_if_0x55c9aa78e260
jmp :label_exit_if_0x55c9aa78dfc0
:label_0x55c9aa78d450
PUSH 0
POP [3]
PUSH rax
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
PUSH rax
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
MUL
PUSH 4
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
MUL
PUSH rax
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
MUL
SUB
POP [3]
PUSH [3]
PUSH [3]
PUSH 0
E
PUSH 0
jbe :label_0x55c9aa78ba50
:label_0x55c9aa78d660
PUSH 1
OUT
PUSH 0
PUSH rax
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
SUB
PUSH 2
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
MUL
DIV
OUT
jmp :label_exit_if_0x55c9aa78d570
:label_0x55c9aa78ba50
PUSH [3]
PUSH 0
A
PUSH 0
jbe :label_0x55c9aa78c140
:label_0x55c9aa78bb70
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
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
SUB
PUSH [3]
ADD
PUSH 2
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
MUL
DIV
OUT
PUSH 0
PUSH rax
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
SUB
PUSH [3]
SUB
PUSH 2
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
MUL
DIV
OUT
jmp :label_exit_if_0x55c9aa78ba80
:label_0x55c9aa78c140
PUSH 0
OUT
jmp :label_exit_if_0x55c9aa78ba80
:label_exit_if_0x55c9aa78ba80
jmp :label_exit_if_0x55c9aa78d570
:label_exit_if_0x55c9aa78d570
jmp :label_exit_if_0x55c9aa78dfc0
:label_exit_if_0x55c9aa78dfc0
PUSH 0
RET
jmp :label_exit_if_0x55c9aa78e140
:label_exit_if_0x55c9aa78e140
