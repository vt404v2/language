#include "middleend.h"

int main(int argc, char *argv[])
{
    const char *input_tree_filename = nullptr;
    const char *output_tree_filename = nullptr;

    if (argc == 3)
    {
        input_tree_filename = argv[1];
        output_tree_filename = argv[2];
    }
    else
        fprintf(stderr, "got incorrect number of arguments");

    treeSetLogFile();
    simplifyTree(input_tree_filename, output_tree_filename);
    treeCloseLogFile();

    return 0;
}