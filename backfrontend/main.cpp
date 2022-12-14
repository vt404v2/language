#include "backfrontend.h"

int main()
{
    treeSetLogFile();
    convertTreeToCode("tree_ilya.txt", "code.txt");
    treeCloseLogFile();
    return 0;
}