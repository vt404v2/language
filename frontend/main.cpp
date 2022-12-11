#include "frontend.h"

int main()
{
    treeSetLogFile();
    convertProgramToTree("quadratic.txt", "tree.txt");
    treeCloseLogFile();
    return 0;
}