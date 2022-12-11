PUSH 0
POP [0]
PUSH 1000
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_not_cond_0x557bf9e39110
:label_0x557bf9e39110
PUSH [0]
PUSH 100
A
PUSH 0
jbe :label_(nil)
:label_0x557bf9e39260
PUSH [0]
OUT
jmp :label_exit_if_0x557bf9e39140
:label_(nil)
jmp :label_exit_if_0x557bf9e39140
:label_exit_if_0x557bf9e39140
PUSH [0]
PUSH 7
SUB
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
ja :label_0x557bf9e39110
:label_not_cond_0x557bf9e39110
PUSH [0]
OUT
HLT
:func_g
PUSH [0]
OUT
PUSH [0]
RET
