PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 6
POP [0]
PUSH [0]
PUSH [0]
call :func_fact
OUT
HLT
:func_fact
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
jbe :label_0x55b1996fc0b0
:label_0x55b1996fc020
PUSH 1
PUSH rax
PUSH 1
SUB
POP rax
RET
jmp :label_exit_if_0x55b1996fbdb0
:label_0x55b1996fc0b0
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
call :func_fact
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
MUL
PUSH rax
PUSH 1
SUB
POP rax
RET
jmp :label_exit_if_0x55b1996fbdb0
:label_exit_if_0x55b1996fbdb0
