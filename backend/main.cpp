#include "backend.h"

int main(int argc, char *argv[])
{
    const char *tree_filename = nullptr;
    const char *main_asm_filename = nullptr;
    const char *func_asm_filename = nullptr;

    if (argc == 4)
    {
        tree_filename = argv[1];
        main_asm_filename = argv[2];
        func_asm_filename = argv[3];
    }
    else
        fprintf(stderr, "got incorrect number of arguments");

    treeSetLogFile();
    convertTreeToAsm(tree_filename, main_asm_filename, func_asm_filename);
    treeCloseLogFile();

    return 0;
}