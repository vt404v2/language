#include "tokenizer.h"

int main()
{
    char filename[] = "program.txt";
    char name_table[BUFFER_SIZE][BUFFER_SIZE] = {};

    Tokens tokens = {};
    ctorTokens(&tokens, 2);

    tokenize(filename, &name_table, &tokens);
    {
    //    printf("SIZE: %zu\n", tokens.size);
    //    for (size_t i = 0; i < tokens.size; i++)
    //    {
    //        printf("token %.2zu: Type: %d ",
    //               i,
    //               tokens.tokens[i].type);
    //        switch (tokens.tokens[i].type)
    //        {
    //            case NUMBER_TOKEN:
    //                printf("Value: %d\n", tokens.tokens[i].value.num_value);
    //                break;
    //            case KEYWORD_TOKEN:
    //                printf("Table id: %zu\n", tokens.tokens[i].value.id_in_table);
    //                break;
    //            case OPERATOR_TOKEN:
    //                printf("Value: %c\n", tokens.tokens[i].value.operation);
    //                break;
    //            case BRACKET_TOKEN:
    //                printf("Value: %c\n", tokens.tokens[i].value.bracket);
    //                break;
    //            case INCORRECT_TYPE_TOKEN:
    //                printf("Value: INCORRECT VALUE\n");
    //                break;
    //        }
    //    }
    }
    Tree tree = {};
    treeCtor(&tree);

    tree.root = readRecursiveDescentNode(&tokens);
    treeDump(&tree, &name_table);

    treeDtor(&tree);
    dtorTokens(&tokens);

    return 0;
}