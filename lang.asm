PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 5
POP [0]
PUSH [0]
PUSH [0]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
call :func_fact
OUT
PUSH 41
HLT
:func_fact
PUSH 1
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
AE
PUSH 0
jbe :label_0x555ef86f8300
:label_0x555ef86f8270
PUSH 1
RET
jmp :label_exit_if_0x555ef86f6df0
:label_0x555ef86f8300
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
PUSH 1
SUB
PUSH rax
PUSH 0
ADD
POP rax
POP [rax]
PUSH [rax]
PUSH rax
PUSH 0
SUB
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
PUSH 1
ADD
RET
call :func_fact
MUL
jmp :label_exit_if_0x555ef86f6df0
:label_exit_if_0x555ef86f6df0
