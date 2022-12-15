PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 1000
POP [0]
PUSH [0]
PUSH [0]
call :func_g
PUSH [0]
OUT
HLT
:func_g
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
OUT
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
A
PUSH 0
jbe :label_(nil)
:label_0x5635881231e0
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
PUSH 7
SUB
call :func_g
PUSH rax
PUSH 1
SUB
POP rax
RET
jmp :label_exit_if_0x5635881230f0
:label_(nil)
jmp :label_exit_if_0x5635881230f0
:label_exit_if_0x5635881230f0
PUSH 0
PUSH rax
PUSH 1
SUB
POP rax
RET
