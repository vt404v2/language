#include "backend.h"

int main()
{
    treeSetLogFile();
    convertTreeToAsm("tree.txt", "lang.asm", "func_def.asm");
    treeCloseLogFile();
    return 0;
}