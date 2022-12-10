#include "tokenizer.h"

void ctorTokens(Tokens *tokens, size_t capacity)
{
    tokens->tokens = (Token_t *) calloc(capacity,
                                        sizeof(tokens->tokens[0]));
    tokens->size = 0;
    tokens->capacity = capacity;
}

void dtorTokens(Tokens *tokens)
{
    free(tokens->tokens);
    tokens->size = 0;
    tokens->capacity = 0;
}

size_t tokenize(const char *filename,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                Tokens *tokens)
{
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr)
        return CANT_OPEN_TREE_FILE;

    long lenOfFile = 0;
    char *tree_buffer = readFileToBuf(fp, &lenOfFile);
    fclose(fp);

    char *readPtr = tree_buffer;

    while (readPtr < tree_buffer + lenOfFile)
    {
        skipSpaces(&readPtr);
        if (tokens->size >= tokens->capacity)
            reallocTokens(tokens);

        if (isalpha(*readPtr))
        {
            tokens->tokens[tokens->size].type = KEYWORD_TOKEN;

            char word[MAX_WORD_LENGTH] = "";
            size_t word_length = 0;
            getWord(&readPtr, word, &word_length);

            size_t position = insertToNameTable(word, name_table);
            tokens->tokens[tokens->size].value.id_in_table = position;
        }
        else if (isdigit(*readPtr) ||
            (*readPtr == '-' && isdigit(*(readPtr + 1))))
        {
            tokens->tokens[tokens->size].type = NUMBER_TOKEN;

            int num = 0;
            int length = 0;
            sscanf(readPtr, "%d%n", &num, &length);

            readPtr += length;
            tokens->tokens[tokens->size].value.num_value = num;
        }
#define TWO_CHARS_OPERATOR(first, second, name)                 \
        if (*readPtr == (first) && *(readPtr + 1) == (second))  \
        {                                                       \
            tokens->tokens[tokens->size].type = OPERATOR_TOKEN; \
            tokens->tokens[tokens->size].value.operation =      \
                (name);                                         \
            readPtr += 2;                                       \
        }

        else TWO_CHARS_OPERATOR('>', '=', GREATER_EQ_OP)
        else TWO_CHARS_OPERATOR('<', '=', BELOW_EQ_OP)
        else TWO_CHARS_OPERATOR('=', '=', EQUAL_OP)
        else TWO_CHARS_OPERATOR('!', '=', NOT_EQ_OP)
        else TWO_CHARS_OPERATOR('&', '&', AND_OP)
        else TWO_CHARS_OPERATOR('|', '|', OR_OP)
#undef TWO_CHARS_OPERATOR
#define ONE_CHAR_OPERATOR(oper, name)                              \
        if (*readPtr == (oper))                                    \
        {                                                          \
            tokens->tokens[tokens->size].type = OPERATOR_TOKEN;    \
            tokens->tokens[tokens->size].value.operation = (name); \
            readPtr++;                                             \
        }

        else ONE_CHAR_OPERATOR('=', EQUAL_OP)
        else ONE_CHAR_OPERATOR('>', GREATER_OP)
        else ONE_CHAR_OPERATOR('<', BELOW_OP)
        else ONE_CHAR_OPERATOR('+', ADD_OP)
        else ONE_CHAR_OPERATOR('-', SUB_OP)
        else ONE_CHAR_OPERATOR('*', MUL_OP)
        else ONE_CHAR_OPERATOR('/', DIV_OP)
        else ONE_CHAR_OPERATOR('^', POW_OP)
        else ONE_CHAR_OPERATOR('!', NOT_OP)
#undef ONE_CHAR_OPERATOR
        else if (*readPtr == '(' ||
            *readPtr == ')' ||
            *readPtr == '{' ||
            *readPtr == '}')
        {
            tokens->tokens[tokens->size].type = BRACKET_TOKEN;
            tokens->tokens[tokens->size].value.bracket = *readPtr;
            readPtr++;
        }
        else if (*readPtr == ',')
        {
            tokens->tokens[tokens->size].type = SPECIAL_TOKEN;
            tokens->tokens[tokens->size].value.special_token = *readPtr;
            readPtr++;
        }
        else
        {
            if (*readPtr == 0)
                break;
            ASSERT_OK(0, "Incorrect token _%c_", *readPtr)
        }
        tokens->size++;
    }

    free(tree_buffer);
}

void reallocTokens(Tokens *tokens)
{
    tokens->capacity *= 2;
    tokens->tokens = (Token_t *) realloc(tokens->tokens,
                                         tokens->capacity
                                             * sizeof(tokens->tokens[0]));
    assert(tokens->tokens != nullptr);
}

size_t insertToNameTable(char *word,
                         char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    bool success = false;
    size_t position = getIdFromNameTable(word, name_table, &success);
    if (success)
        return position;

    for (size_t i = 0; i < BUFFER_SIZE; i++)
    {
        if (strcasecmp((*name_table)[i], "\0") == 0)
        {
            memcpy((*name_table)[i], word, BUFFER_SIZE);
            return i;
        }
    }
    assert(0 && "NAME TABLE IS SO SMALL\n");
}

size_t getIdFromNameTable(char *word,
                          char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                          bool *success)
{
    for (size_t i = 0; i < BUFFER_SIZE; i++)
    {
        if (strcasecmp((*name_table)[i], word) == 0)
        {
            *success = true;
            return i;
        }
    }
    *success = false;
    return -1;
}

void getWord(char **readPtr, char *word, size_t *word_length)
{
    size_t length = 0;
    do
    {
        word[length] = **readPtr;
        length++;
        (*readPtr)++;
    }
    while (isalpha(**readPtr) || **readPtr == '_');
    *word_length = length;
}

void skipSpaces(char **readPtr)
{
    while (**readPtr == ' ' || **readPtr == '\n')
        (*readPtr)++;
}
