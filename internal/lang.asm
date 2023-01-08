PUSH 9999
POP rax
PUSH 20
PUSH 8
call :func_print_circle
SHOW_RAM
HLT
:func_print_circle
PUSH rax
PUSH 1
SUB
PUSH 0
ADD
POP rax
POP [rax]
PUSH rax
PUSH 1
ADD
PUSH 0
SUB
POP rax
PUSH rax
PUSH 1
SUB
PUSH 1
ADD
POP rax
POP [rax]
PUSH rax
PUSH 1
ADD
PUSH 1
SUB
POP rax
PUSH rax
PUSH 5
SUB
POP rax
PUSH 0
POP [2]
PUSH 0
POP [2]
PUSH [2]
PUSH 0
POP [3]
PUSH 0
POP [3]
PUSH [3]
PUSH 0
POP [4]
PUSH 0
POP [4]
PUSH [4]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH [2]
A
PUSH 0
jbe :label_not_cond_0x55bec5c4d630
:label_0x55bec5c4d630
PUSH 0
POP [3]
PUSH [3]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH [3]
A
PUSH 0
jbe :label_not_cond_0x55bec5c4d7e0
:label_0x55bec5c4d7e0
PUSH [2]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH 2
DIV
SUB
PUSH [2]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH 2
DIV
SUB
MUL
PUSH [3]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH 2
DIV
SUB
PUSH [3]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH 2
DIV
SUB
MUL
ADD
POP [4]
PUSH [4]
PUSH rax
PUSH 4
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 4
SUB
POP rax
PUSH rax
PUSH 4
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 4
SUB
POP rax
MUL
PUSH [4]
A
PUSH 0
jbe :label_0x55bec5c4dff0
:label_0x55bec5c4de40
PUSH 1
PUSH [2]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
MUL
PUSH [3]
ADD
PUSH 1024
ADD
POP rbx
POP [rbx]
PUSH [rbx]
jmp :label_exit_if_0x55bec5c4dcf0
:label_0x55bec5c4dff0
PUSH 0
PUSH [2]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
MUL
PUSH [3]
ADD
PUSH 1024
ADD
POP rbx
POP [rbx]
PUSH [rbx]
jmp :label_exit_if_0x55bec5c4dcf0
:label_exit_if_0x55bec5c4dcf0
PUSH [3]
PUSH 1
ADD
POP [3]
PUSH [3]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH [3]
A
PUSH 0
ja :label_0x55bec5c4d7e0
:label_not_cond_0x55bec5c4d7e0
PUSH [2]
PUSH 1
ADD
POP [2]
PUSH [2]
PUSH rax
PUSH 5
ADD
POP rax
PUSH [rax]
PUSH rax
PUSH 5
SUB
POP rax
PUSH [2]
A
PUSH 0
ja :label_0x55bec5c4d630
:label_not_cond_0x55bec5c4d630
PUSH 0
PUSH rax
PUSH 5
ADD
POP rax
RET
