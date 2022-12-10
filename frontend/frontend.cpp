#include "frontend.h"

void convertProgramToTree(const char *filename,
                          const char *tree_filename)
{
    char name_table[BUFFER_SIZE][BUFFER_SIZE] = {};

    Tokens tokens = {};
    ctorTokens(&tokens, 2);

    tokenize(filename, &name_table, &tokens);

    Tree tree = {};
    treeCtor(&tree);

    tree.root = readRecursiveDescentNode(&tokens, &name_table);
    treeDump(&tree);

    FILE *tree_file = fopen(tree_filename, "w");
    treeSaveToFile(&tree, &name_table, tree_file);
    fclose(tree_file);

    treeDtor(&tree);

    Tree result_tree = {};
    treeCtor(&result_tree);
    readTree(&result_tree, "tree.txt");
    treeDump(&result_tree);
    treeDtor(&result_tree);

    dtorTokens(&tokens);
}