PUSH 0
POP [0]
PUSH 1000
PUSH 7
SUB
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_not_cond_0x559c248a3f30
:label_0x559c248a3f30
PUSH [0]
PUSH 100
A
PUSH 0
jbe :label_(nil)
:label_0x559c248a4a60
PUSH [0]
OUT
jmp :label_exit_if_0x559c248a3f60
:label_(nil)
jmp :label_exit_if_0x559c248a3f60
:label_exit_if_0x559c248a3f60
PUSH [0]
PUSH 7
SUB
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
ja :label_0x559c248a3f30
:label_not_cond_0x559c248a3f30
PUSH 0
POP [0]
PUSH [0]
HLT