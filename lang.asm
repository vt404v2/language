PUSH 666
POP rax
PUSH 0
POP [3]
IN
POP [3]
PUSH [3]
PUSH 0
POP [4]
PUSH 0
POP [4]
PUSH [4]
PUSH 0
POP [5]
PUSH 1
POP [5]
PUSH [5]
PUSH [3]
POP [rax]
PUSH rax
PUSH 1
ADD
POP rax
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
PUSH rax
PUSH 3
SUB
POP rax
call :func_fib
HLT
:func_fib
PUSH 0
PUSH rax
PUSH 0
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 0
SUB
POP rax
AE
PUSH 0
jbe :label_0x55a462e05700
:label_0x55a462e05430
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
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
A
PUSH 0
jbe :label_0x55a462e055e0
:label_0x55a462e05550
PUSH rax
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
OUT
jmp :label_exit_if_0x55a462e05460
:label_0x55a462e055e0
PUSH rax
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
OUT
jmp :label_exit_if_0x55a462e05460
:label_exit_if_0x55a462e05460
PUSH 0
RET
jmp :label_exit_if_0x55a462e05340
:label_0x55a462e05700
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
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
A
PUSH 0
jbe :label_0x55a462e05c70
:label_0x55a462e05820
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
PUSH 1
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 1
SUB
POP rax
ADD
PUSH rax
PUSH 2
ADD
POP rax
POP [rax]
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
SUB
POP rax
call :func_fib
RET
jmp :label_exit_if_0x55a462e05730
:label_0x55a462e05c70
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
PUSH 2
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 2
SUB
POP rax
ADD
PUSH rax
PUSH 1
ADD
POP rax
POP [rax]
PUSH [rax]
PUSH rax
PUSH 1
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
SUB
POP rax
call :func_fib
RET
jmp :label_exit_if_0x55a462e05730
:label_exit_if_0x55a462e05730
jmp :label_exit_if_0x55a462e05340
:label_exit_if_0x55a462e05340
