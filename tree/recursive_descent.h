#ifndef RECURSIVE_DESCENT__RECURSIVE_DESCENT_H
#define RECURSIVE_DESCENT__RECURSIVE_DESCENT_H

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "ctype.h"
#include "cmath"
#include "tree.h"

// TODO: grammar
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

Node *recursiveDescent(Tokens *tokens,
                       size_t *index,
                       char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getLogOp(Tokens *tokens,
               size_t *index,
               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getAddSub(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getMulDiv(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getPow(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getLog(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getSin(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getCos(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);


Node *getVarInit(Tokens *tokens,
                 size_t *index,
                 char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getVarDec(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getIf(Tokens *tokens,
            size_t *index,
            char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getWhile(Tokens *tokens,
               size_t *index,
               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getCodeBlock(Tokens *tokens,
                   size_t *index,
                   char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getDefFunction(Tokens *tokens,
                     size_t *index,
                     char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getPrimaryExpression(Tokens *tokens,
                           size_t *index,
                           char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getValue(Tokens *tokens,
               size_t *index,
               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getVariable(Tokens *tokens,
                  size_t *index,
                  char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

bool is_keyword(char *word);

#define ASSERT_OK(value, error, ...)                                  \
        if (!(value))                                                 \
        {                                                             \
            fprintf(stderr, "Error occurred: " error, ##__VA_ARGS__); \
            abort();                                                  \
        }

#define TOKEN tokens->tokens[*index]

#endif //RECURSIVE_DESCENT__RECURSIVE_DESCENT_H
