#include "frontend.h"

int main(int argc, char *argv[])
{
    const char *program_filename = nullptr;
    const char *tree_filename = nullptr;

    if (argc == 3)
    {
        program_filename = argv[1];
        tree_filename = argv[2];
    }
    else
        fprintf(stderr, "got incorrect number of arguments");

    treeSetLogFile();
    convertProgramToTree(program_filename, tree_filename);
    treeCloseLogFile();

    return 0;
}