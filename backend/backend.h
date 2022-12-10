#ifndef LANGUAGE__BACKEND_H
#define LANGUAGE__BACKEND_H

#include "../tree/tree.h"

void convertTreeToAsm(const char *tree_filename,
                      const char *asm_filename);

void assemble(Tree *tree, Node *node, FILE *fp);

void assemble_node(Tree *tree, Node *node, FILE *fp);

#endif //LANGUAGE__BACKEND_H
