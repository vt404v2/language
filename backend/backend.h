#ifndef LANGUAGE__BACKEND_H
#define LANGUAGE__BACKEND_H

#include "../tree/tree.h"

void convertTreeToAsm(const char *tree_filename,
                      const char *asm_filename,
                      const char *asm_func_filename);

void assemble(Tree *tree, Node *node,
              FILE *main_fp, FILE *func_fp);


void fixArgVars(Tree *tree, Node *node);

void registerArgs(Tree *tree, Node *node, size_t *index);

void assemble_node(Tree *tree, Node *node,
                   FILE *main_fp, FILE *func_fp);

void assemble_args(Tree *tree, Node *node, FILE *fp);

void pushArgs(Tree *tree, Node *node, FILE *fp, size_t *new_arg_id, size_t last_num_args);

void searchWhereCall(Node *nodeSearchIn, Node *node, bool *found, size_t *func_id);

#endif //LANGUAGE__BACKEND_H
