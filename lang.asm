PUSH 0
POP [0]
PUSH 0
POP [1]
PUSH 1000
PUSH 7
SUB
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_not_cond_0x561b833c4070
:label_0x561b833c4070
PUSH [0]
PUSH 100
A
PUSH 0
jbe :label_(nil)
:label_0x561b833c41c0
PUSH [0]
OUT
jmp :label_exit_if_0x561b833c40a0
:label_(nil)
jmp :label_exit_if_0x561b833c40a0
:label_exit_if_0x561b833c40a0
PUSH [0]
PUSH 7
SUB
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
ja :label_0x561b833c4070
:label_not_cond_0x561b833c4070
PUSH [0]
OUT
E
HLT