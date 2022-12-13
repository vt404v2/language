PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 6
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
jbe :label_0x55839f0d5090
:label_0x55839f0d5000
PUSH 1
PUSH rax
PUSH 1
SUB
POP rax
RET
jmp :label_exit_if_0x55839f0d4f10
:label_0x55839f0d5090
PUSH 0
POP [2]
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
POP [2]
PUSH [2]
PUSH [2]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
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
jmp :label_exit_if_0x55839f0d4f10
:label_exit_if_0x55839f0d4f10
