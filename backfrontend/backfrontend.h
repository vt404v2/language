#ifndef LANGUAGE_BACKFRONTEND_BACKFRONTEND_H
#define LANGUAGE_BACKFRONTEND_BACKFRONTEND_H

#include "../tree/tree.h"

const int NUM_SPACES = 4;

void convertTreeToCode(const char *tree_filename, const char *code_filename);

void printNode(Tree *tree, Node *node, FILE *fp, int num_spaces);

void printArgs(Tree *tree, Node *node, FILE *fp, size_t *num_args);

void printSpaces(int num_spaces, FILE *fp);

#endif //LANGUAGE_BACKFRONTEND_BACKFRONTEND_H
