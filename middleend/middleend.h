#ifndef LANGUAGE_MIDDLEEND_MIDDLEEND_H
#define LANGUAGE_MIDDLEEND_MIDDLEEND_H

#include "../tree/tree.h"

void simplifyTree(const char *input_tree_filename, const char *output_tree_filename);

void simplifyNode(Node *node);

void convConst(Node *node, bool *changed);

void deleteNeutralElements(Node *node, bool *changed);

void moveNodeUp(Node *node,
                Node *node_to_up,
                Node *node_to_delete,
                bool *changed);

void changeNodeTypeToNumber(Node *node,
                            int value,
                            bool *changed);

Node *copyNode(Node *node);

#endif //LANGUAGE_MIDDLEEND_MIDDLEEND_H
