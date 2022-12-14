#include "backfrontend.h"

int main(int argc, char *argv[])
{
    const char *tree_filename = nullptr;
    const char *code_filename = nullptr;

    if (argc == 3)
    {
        tree_filename = argv[1];
        code_filename = argv[2];
    }
    else
        fprintf(stderr, "got incorrect number of arguments");

    treeSetLogFile();
    convertTreeToCode(tree_filename, code_filename);
    treeCloseLogFile();

    return 0;
}