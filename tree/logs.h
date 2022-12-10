#ifndef DIFFERENTIATOR_TREE_LOGS_H
#define DIFFERENTIATOR_TREE_LOGS_H

#include "tree.h"

void treeSetLogFile();

void treeClearGraphLogFile();

void treeCloseLogFile();

size_t treeDump(Tree *tree);

size_t createGraph(Tree *tree, const char *photo_name);

size_t createGraphNodes(Tree *tree,
                        Node *node,
                        FILE *fp);

size_t createGraphEdges(Node *node, FILE *fp);

void getValueOfNode(Tree *tree,
                    const Node *node,
                    char (*node_value)[BUFFER_SIZE]);

#endif //DIFFERENTIATOR_TREE_LOGS_H
