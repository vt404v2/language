PUSH 666
POP rax
PUSH 0
POP [3]
PUSH 6
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
jbe :label_0x561eac6a0580
:label_0x561eac6a07f0
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
jbe :label_0x561eac6a0d90
:label_0x561eac6a0d00
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
jmp :label_exit_if_0x561eac6a0820
:label_0x561eac6a0d90
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
jmp :label_exit_if_0x561eac6a0820
:label_exit_if_0x561eac6a0820
PUSH 0
RET
jmp :label_exit_if_0x561eac6a0400
:label_0x561eac6a0580
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
jbe :label_0x561eac69fa10
:label_0x561eac6a0970
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
jmp :label_exit_if_0x561eac6a05b0
:label_0x561eac69fa10
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
jmp :label_exit_if_0x561eac6a05b0
:label_exit_if_0x561eac6a05b0
jmp :label_exit_if_0x561eac6a0400
:label_exit_if_0x561eac6a0400
