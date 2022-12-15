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
jbe :label_0x5606eafc64e0
:label_0x5606eafc6390
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
jmp :label_exit_if_0x5606eafc62a0
:label_0x5606eafc64e0
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
jbe :label_0x5606eafc6f30
:label_0x5606eafc6600
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
jbe :label_0x5606eafc6840
:label_0x5606eafc6720
PUSH 1
OUT
PUSH 0
OUT
jmp :label_exit_if_0x5606eafc6630
:label_0x5606eafc6840
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
jbe :label_0x5606eafc6a50
:label_0x5606eafc69c0
PUSH 0
OUT
jmp :label_exit_if_0x5606eafc6870
:label_0x5606eafc6a50
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
jmp :label_exit_if_0x5606eafc6870
:label_exit_if_0x5606eafc6870
jmp :label_exit_if_0x5606eafc6630
:label_exit_if_0x5606eafc6630
jmp :label_exit_if_0x5606eafc6510
:label_0x5606eafc6f30
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
jbe :label_0x5606eafc7560
:label_0x5606eafc72f0
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
jmp :label_exit_if_0x5606eafc7200
:label_0x5606eafc7560
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_0x5606eafc7cb0
:label_0x5606eafc7680
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
jmp :label_exit_if_0x5606eafc7590
:label_0x5606eafc7cb0
PUSH 0
OUT
jmp :label_exit_if_0x5606eafc7590
:label_exit_if_0x5606eafc7590
jmp :label_exit_if_0x5606eafc7200
:label_exit_if_0x5606eafc7200
jmp :label_exit_if_0x5606eafc6510
:label_exit_if_0x5606eafc6510
jmp :label_exit_if_0x5606eafc62a0
:label_exit_if_0x5606eafc62a0
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
jbe :label_0x5606eafc8130
:label_0x5606eafc8040
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
jmp :label_exit_if_0x5606eafc7f50
:label_0x5606eafc8130
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
jmp :label_exit_if_0x5606eafc7f50
:label_exit_if_0x5606eafc7f50
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
jbe :label_0x5606eafc8670
:label_0x5606eafc85e0
PUSH 993
OUT
jmp :label_exit_if_0x5606eafc84f0
:label_0x5606eafc8670
PUSH 0
OUT
jmp :label_exit_if_0x5606eafc84f0
:label_exit_if_0x5606eafc84f0
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
