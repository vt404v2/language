PUSH 666
POP rax
PUSH 0
POP [6]
PUSH 1
POP [6]
PUSH [6]
PUSH 0
POP [7]
PUSH 5
POP [7]
PUSH [7]
PUSH 0
POP [8]
PUSH 6
POP [8]
PUSH [8]
PUSH [6]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
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
jbe :label_0x55f2385fec90
:label_0x55f2385fde80
PUSH rax
PUSH 0
SUB
POP rax
call :func_solve_linear
RET
jmp :label_exit_if_0x55f2385ff800
:label_0x55f2385fec90
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
jbe :label_0x55f2385fe030
:label_0x55f2385fe630
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
jbe :label_0x55f2385fe750
:label_0x55f2385fede0
PUSH 0
OUT
jmp :label_exit_if_0x55f2385fe660
:label_0x55f2385fe750
PUSH 1
OUT
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
OUT
jmp :label_exit_if_0x55f2385fe660
:label_exit_if_0x55f2385fe660
jmp :label_exit_if_0x55f2385fecc0
:label_0x55f2385fe030
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
jbe :label_(nil)
:label_0x55f2385fdc40
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
jmp :label_exit_if_0x55f2385fe390
:label_(nil)
jmp :label_exit_if_0x55f2385fe390
:label_exit_if_0x55f2385fe390
PUSH 404
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
jmp :label_exit_if_0x55f2385fecc0
:label_exit_if_0x55f2385fecc0
PUSH 0
RET
jmp :label_exit_if_0x55f2385ff800
:label_exit_if_0x55f2385ff800
:func_solve_linear
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
jbe :label_0x55f2385fcb70
:label_0x55f2385ff290
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
jbe :label_0x55f2385fcae0
:label_0x55f2385fca50
PUSH 993
OUT
jmp :label_exit_if_0x55f2385ff2c0
:label_0x55f2385fcae0
PUSH 0
OUT
jmp :label_exit_if_0x55f2385ff2c0
:label_exit_if_0x55f2385ff2c0
jmp :label_exit_if_0x55f2385ff1a0
:label_0x55f2385fcb70
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
OUT
jmp :label_exit_if_0x55f2385ff1a0
:label_exit_if_0x55f2385ff1a0
PUSH 0
RET
