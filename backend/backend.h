#ifndef LANGUAGE__BACKEND_H
#define LANGUAGE__BACKEND_H

#include "../tree/tree.h"

void convertTreeToAsm(const char *tree_filename,
                      const char *asm_filename,
                      const char *asm_func_filename);

void assemble(Tree *tree,
              Node *node,
              FILE *main_fp,
              FILE *func_fp);

void assemble_node(Tree *tree,
                   Node *node,
                   FILE *main_fp,
                   FILE *func_fp);

void assembleArrayDec(Tree *tree,
                      Node *node,
                      FILE *main_fp,
                      FILE *func_fp);

void assembleArray(Tree *tree,
                   Node *node,
                   FILE *main_fp,
                   FILE *func_fp);

void assembleOperator(Tree *tree,
                      Node *node,
                      FILE *main_fp,
                      FILE *func_fp);

void assembleAssign(Tree *tree,
                    Node *node,
                    FILE *main_fp,
                    FILE *func_fp);

void assembleWhile(Tree *tree,
                   Node *node,
                   FILE *main_fp,
                   FILE *func_fp);

void assembleIf(Tree *tree,
                Node *node,
                FILE *main_fp,
                FILE *func_fp);

void assembleDef(Tree *tree,
                 Node *node,
                 FILE *main_fp,
                 FILE *func_fp);

void countNodes(Node *node,
                NodeType search_value,
                size_t *index);

void changeLocalVarsNodesValues(Node *node,
                                Node *body_node,
                                NodeType search_value,
                                size_t *index,// new index
                                size_t num_variables);

void changeLocalVarsNodesValuesInBody(Node *node,
                                      size_t old_value,
                                      size_t new_value);

void assembleCall(Tree *tree,
                  Node *node,
                  FILE *main_fp,
                  FILE *func_fp);

void searchWhereCall(Node *nodeSearchIn,
                     Node *node,
                     bool *found,
                     size_t *func_id);

void pushArgs(Tree *tree,
              Node *node,
              FILE *fp,
              size_t *new_arg_id,
              size_t last_num_args);

void assembleReturn(Tree *tree,
                    Node *node,
                    FILE *main_fp,
                    FILE *func_fp);

void assembleLocalVariable(Tree *tree,
                           Node *node,
                           FILE *main_fp,
                           FILE *func_fp);



#endif //LANGUAGE__BACKEND_H
