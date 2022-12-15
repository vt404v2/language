#include "frontend.h"

void convertProgramToTree(const char *filename,
                          const char *standard_tree_filename,
                          const char *backend_tree_filename)
{
    assert(filename != nullptr);
    assert(standard_tree_filename != nullptr);
    assert(backend_tree_filename != nullptr);

    char name_table[BUFFER_SIZE][BUFFER_SIZE] = {};

    Tokens tokens = {};
    ctorTokens(&tokens, 2);

    tokenize(filename, &name_table, &tokens);

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
//                printf("Value: %d\n", tokens.tokens[i].value.operation);
//                break;
//            case BRACKET_TOKEN:
//                printf("Value: %c\n", tokens.tokens[i].value.bracket);
//                break;
//            case SPECIAL_TOKEN:
//                printf("Value: %c\n", tokens.tokens[i].value.special_token);
//                break;
//            case INCORRECT_TYPE_TOKEN:
//                printf("Value: INCORRECT VALUE\n");
//                break;
//        }
//    }

    Tree tree = {};
    treeCtor(&tree);

    tree.root = readRecursiveDescentNode(&tokens, &name_table);
    treeDump(&tree);

    FILE *standard_tree_file = fopen(standard_tree_filename, "w");
    FILE *backend_tree_file = fopen(backend_tree_filename, "w");
    treeSaveToFile(&tree, &name_table, standard_tree_file, backend_tree_file);
    fclose(standard_tree_file);
    fclose(backend_tree_file);

    treeDtor(&tree);

    Tree result_tree = {};
    treeCtor(&result_tree);
    readTree(&result_tree, "tree.txt");
    treeDump(&result_tree);
    treeDtor(&result_tree);

    dtorTokens(&tokens);
}