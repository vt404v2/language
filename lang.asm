PUSH 666
POP rax
PUSH 0
POP [0]
PUSH 100
POP [0]
PUSH [0]
PUSH [0]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH rax
PUSH 1
SUB
POP rax
call :func_g
POP [0]
PUSH [0]
PUSH [0]
OUT
PUSH [0]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
PUSH rax
PUSH 1
SUB
POP rax
call :func_g
POP [0]
PUSH [0]
PUSH [0]
OUT
HLT
:func_g
PUSH 10
PUSH [rax]
A
PUSH 0
jbe :label_0x55d70ae31580
:label_0x55d70ae314f0
PUSH [rax]
RET
jmp :label_exit_if_0x55d70ae30f50
:label_0x55d70ae31580
PUSH [rax]
OUT
PUSH [rax]
PUSH 1
SUB
POP [rax]
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
call :func_g
RET
jmp :label_exit_if_0x55d70ae30f50
:label_exit_if_0x55d70ae30f50
