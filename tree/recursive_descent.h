#ifndef RECURSIVE_DESCENT__RECURSIVE_DESCENT_H
#define RECURSIVE_DESCENT__RECURSIVE_DESCENT_H

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "ctype.h"
#include "cmath"
#include "tree.h"

// grammar of recursive descent
// recursiveDescent ::= getLogOp '\0'
// getAddSub ::= getMulDiv {['+', '-'] getMulDiv}*
// getMulDiv ::= getPrimaryExpression {['+', '-'] getPrimaryExpression}*
// getVarInit ::= ['x'-'z', 'X'-'Z', '_'] {'=' getVarInit | getLogOp }*
// getVarDec ::= 'var' ['x'-'z', 'X'-'Z', '_']
// getIf ::= 'if' getPrimaryExpression getPrimaryExpression {'else' getPrimaryExpression}
// getWhile ::= 'while' getPrimaryExpression getPrimaryExpression
// getSqrt ::= 'sqrt' getPrimaryExpression
// getInputFunction ::= input '(' ')'
// getOutputFunction ::= output()
// getReturn ::= 'return' getLogOp
// getCodeBlock ::= '{' {getLogOp}* '}'
// getDefFunction ::= 'def' ['x'-'z', 'X'-'Z', '_']
//                    '('
//                      {['x'-'z', 'X'-'Z', '_'] ','}+ ['x'-'z', 'X'-'Z', '_'] |
//                                                     ['x'-'z', 'X'-'Z', '_'] |
//                    ')'
// getCallFunction ::= ['x'-'z', 'X'-'Z', '_']
//                    '('
//                      {['x'-'z', 'X'-'Z', '_'] ','}+ ['x'-'z', 'X'-'Z', '_'] |
//                                                     ['x'-'z', 'X'-'Z', '_'] |
//                    ')'
// getNegativeExpression ::= '-' getLogOp
// getPrimaryExpression ::= getVarDec | getVarInit | getIf | getWhile |
//                          getSqrt | getInputFunction | getOutFunction |
//                          getReturn | getDefFunction | getCallFunction |
//                          '{' getCodeBlock '}' |
//                          '(' getNegativeExpression | getLogOp ')' | getVariable | getValue
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

Node *getVarDec(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getVarInit(Tokens *tokens,
                 size_t *index,
                 char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getIf(Tokens *tokens,
            size_t *index,
            char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getWhile(Tokens *tokens,
               size_t *index,
               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getSqrt(Tokens *tokens,
              size_t *index,
              char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getSin(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getCos(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getInputFunction(Tokens *tokens,
                       size_t *index,
                       char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getOutFunction(Tokens *tokens,
                     size_t *index,
                     char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getReturn(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getCodeBlock(Tokens *tokens,
                   size_t *index,
                   char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getDefFunction(Tokens *tokens,
                     size_t *index,
                     char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

void changeFuncVarsToArgVariables(Node *node, Node *params);

void checkId(Node *node, Node *params, bool *is_arg_var);

Node *getCallFunction(Tokens *tokens,
                      size_t *index,
                      char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *getNegativeExpression(Tokens *tokens,
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
