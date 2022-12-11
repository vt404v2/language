#ifndef LANGUAGE__BACKEND_H
#define LANGUAGE__BACKEND_H

#include "../tree/tree.h"

void convertTreeToAsm(const char *tree_filename,
                      const char *asm_filename,
                      const char *asm_func_filename);

void assemble(Tree *tree, Node *node,
              FILE *main_fp, FILE *func_fp);

void assemble_node(Tree *tree, Node *node,
                   FILE *main_fp, FILE *func_fp);

void assemble_args(Tree *tree, Node *node, FILE *fp);

void pushArgs(Tree *tree, Node *node, FILE *fp);

#endif //LANGUAGE__BACKEND_H
