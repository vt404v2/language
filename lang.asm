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
jbe :label_0x557330960580
:label_0x5573309607f0
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
jbe :label_0x557330960d90
:label_0x557330960d00
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
jmp :label_exit_if_0x557330960820
:label_0x557330960d90
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
jmp :label_exit_if_0x557330960820
:label_exit_if_0x557330960820
PUSH 0
RET
jmp :label_exit_if_0x557330960400
:label_0x557330960580
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
jbe :label_0x55733095fa10
:label_0x557330960970
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
jmp :label_exit_if_0x5573309605b0
:label_0x55733095fa10
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
jmp :label_exit_if_0x5573309605b0
:label_exit_if_0x5573309605b0
jmp :label_exit_if_0x557330960400
:label_exit_if_0x557330960400
