PUSH 0
POP [0]
PUSH 1000
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
jbe :label_not_cond_0x5631ed08eed0
:label_0x5631ed08eed0
PUSH [0]
PUSH 100
A
PUSH 0
jbe :label_(nil)
:label_0x5631ed08f020
PUSH [0]
OUT
jmp :label_exit_if_0x5631ed08ef00
:label_(nil)
jmp :label_exit_if_0x5631ed08ef00
:label_exit_if_0x5631ed08ef00
PUSH [0]
PUSH 7
SUB
POP [0]
PUSH [0]
PUSH [0]
PUSH 0
A
PUSH 0
ja :label_0x5631ed08eed0
:label_not_cond_0x5631ed08eed0
PUSH [0]
OUT
HLT