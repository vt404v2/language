#ifndef RECURSIVE_DESCENT__RECURSIVE_DESCENT_H
#define RECURSIVE_DESCENT__RECURSIVE_DESCENT_H

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "ctype.h"
#include "cmath"
#include "tree.h"

// grammar of recurrent descent
// recursiveDescent ::= getAddSub '\0'
// getAddSub ::= getMulDiv {['+', '-'] getMulDiv}*
// getMulDiv ::= getPow {['+', '-'] getPow}*
// getPow ::= getLog {getPow ['^'] getLog}*
// getLog ::= {["log("]? getSin} | getSin
// getSin ::= {["sin("]? getCos} | getCos
// getCos ::= {["cos("]? getBrackets} | getBrackets
// getPrimaryExpression ::= '(' getAddSub ')' | getValue | getVariable
// getValue ::= [double] | getVariable
// getVariable ::= ['x'-'z', 'X'-'Z']

Node *recursiveDescent(Tokens *tokens, size_t *index);

Node *getAddSub(Tokens *tokens, size_t *index);

Node *getMulDiv(Tokens *tokens, size_t *index);

Node *getPow(Tokens *tokens, size_t *index);

Node *getLog(Tokens *tokens, size_t *index);

Node *getSin(Tokens *tokens, size_t *index);

Node *getCos(Tokens *tokens, size_t *index);

Node *getPrimaryExpression(Tokens *tokens, size_t *index);

Node *getValue(Tokens *tokens, size_t *index);

Node *getVariable(Tokens *tokens, size_t *index);

#define ASSERT_OK(value, error, ...)                                  \
        if (!(value))                                                 \
        {                                                             \
            fprintf(stderr, "Error occurred: " error, ##__VA_ARGS__); \
            abort();                                                  \
        }

#define TOKEN tokens->tokens[*index]

#endif //RECURSIVE_DESCENT__RECURSIVE_DESCENT_H
