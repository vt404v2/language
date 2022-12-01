#ifndef LANGUAGE__TOKENIZER_H
#define LANGUAGE__TOKENIZER_H

#include "tree/tree.h"
#include "tree/logs.h"


void ctorTokens(Tokens *tokens, size_t capacity);

void dtorTokens(Tokens *tokens);

size_t tokenize(char *filename,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                Tokens *tokens);

void reallocTokens(Tokens *tokens);

size_t insertToNameTable(char *word,
                         char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

size_t getIdFromNameTable(char *word,
                          char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                          bool *success);

void getWord(char **readPtr, char *word, size_t *word_length);

void skipSpaces(char **readPtr);

#endif //LANGUAGE__TOKENIZER_H
