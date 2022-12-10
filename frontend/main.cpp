#include "frontend.h"

int main()
{
    treeSetLogFile();
    convertProgramToTree("program.txt", "tree.txt");
    treeCloseLogFile();
    return 0;
}