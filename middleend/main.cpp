#include "middleend.h"

int main(int argc, char *argv[])
{
    const char *standard_tree_filename = nullptr;
    const char *output_standard_tree_filename = nullptr;

    if (argc == 3)
    {
        standard_tree_filename = argv[1];
        output_standard_tree_filename = argv[2];
    }
    else
        fprintf(stderr, "got incorrect number of arguments");

    treeSetLogFile();
    simplifyTree(standard_tree_filename,
                 output_standard_tree_filename);
    treeCloseLogFile();

    return 0;
}