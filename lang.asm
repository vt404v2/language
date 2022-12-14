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
POP raxPUSH 1
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
jbe :label_0x558ac2b48e80
:label_0x558ac2b48df0
PUSH 1
PUSH rax
PUSH 1
SUB
POP rax
RET
jmp :label_exit_if_0x558ac2b49000
:label_0x558ac2b48e80
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
jmp :label_exit_if_0x558ac2b49000
:label_exit_if_0x558ac2b49000
