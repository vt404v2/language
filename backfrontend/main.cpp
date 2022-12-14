#include "backfrontend.h"

int main()
{
    treeSetLogFile();
    convertTreeToCode("tree.txt", "code.txt");
    treeCloseLogFile();
    return 0;
}