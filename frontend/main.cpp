#include "frontend.h"

int main(int argc, char *argv[])
{
    const char *program_filename = nullptr;
    const char *standard_tree_filename = nullptr;
    const char *backend_tree_filename = nullptr;

    if (argc == 4)
    {
        program_filename = argv[1];
        standard_tree_filename = argv[2];
        backend_tree_filename = argv[3];
    }
    else
        fprintf(stderr, "got incorrect number of arguments");

    treeSetLogFile();
    convertProgramToTree(program_filename, standard_tree_filename, backend_tree_filename);
    treeCloseLogFile();

    return 0;
}