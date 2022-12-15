#include "frontend.h"

void convertProgramToTree(const char *filename,
                          const char *standard_tree_filename)
{
    assert(filename != nullptr);
    assert(standard_tree_filename != nullptr);

    char name_table[BUFFER_SIZE][BUFFER_SIZE] = {};

    Tokens tokens = {};
    ctorTokens(&tokens, 2);

    tokenize(filename, &name_table, &tokens);

    Tree tree = {};
    treeCtor(&tree);

    tree.root = readRecursiveDescentNode(&tokens, &name_table);
    treeDump(&tree);

    FILE *standard_tree_file = fopen(standard_tree_filename, "w");
    treeSaveToFile(&tree, &name_table, standard_tree_file);
    fclose(standard_tree_file);

    treeDtor(&tree);

    Tree result_tree = {};
    treeCtor(&result_tree);
    readTree(&result_tree, "tree.txt");
    treeDump(&result_tree);
    treeDtor(&result_tree);

    dtorTokens(&tokens);
}