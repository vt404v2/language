#include "utils.h"

long getLenOfFile(FILE *fp)
{
    struct stat buff = {};
    fstat(fileno(fp), &buff);
    long lenOfFile = buff.st_size;
    return lenOfFile;
}

char *readFileToBuf(FILE *fp, long *lenOfFile)
{
    assert(fp != nullptr);
    assert(lenOfFile != nullptr);

    *lenOfFile = getLenOfFile(fp);

    char *txt = (char *) calloc(*lenOfFile + 1, sizeof(char));
    if (txt == nullptr)
    {
        fprintf(stderr, "Can't allocate memory.");
    }
    fread(txt, sizeof(char), *lenOfFile, fp);
    return txt;
}

size_t gets(char *s)
{
    assert(s != nullptr);

    size_t len = 0;
    char c = ' ';
    while (c != '\n' and c != EOF)
    {
        len++;
        c = getchar();
        if (c != EOF)
        {
            *s = c;
            s++;
        }
        if (c == EOF)
        {
            *s = '\0';
        }
    }
    return len;
}

int skipUnusedSymbols()
{
    int symbol = getchar();

    while (symbol != '\n')
    {
        if (symbol == EOF)
            return 0;
        symbol = getchar();
    }

    return 0;
}