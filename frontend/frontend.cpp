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
    treeDump(&tree, &name_table);

    FILE *tree_file = fopen(tree_filename, "w");
    treeSaveToFile(&tree, tree_file);
    fclose(tree_file);

    treeDtor(&tree);
    dtorTokens(&tokens);
}