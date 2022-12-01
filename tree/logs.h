#ifndef DIFFERENTIATOR_TREE_LOGS_H
#define DIFFERENTIATOR_TREE_LOGS_H

#include "tree.h"

void treeSetLogFile();

void treeClearGraphLogFile();

void treeCloseLogFile();

size_t treeDump(Tree *tree,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

size_t createGraph(Tree *tree, const char *photo_name,
                   char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

size_t createGraphNodes(Node *node,
                        FILE *fp,
                        char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

size_t createGraphEdges(Node *node, FILE *fp);

void getValueOfNode(const Node *node,
                    char (*node_value)[BUFFER_SIZE],
                    char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

#endif //DIFFERENTIATOR_TREE_LOGS_H
