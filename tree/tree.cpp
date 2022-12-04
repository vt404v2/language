#include "tree.h"

size_t treeCtor(Tree *tree)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)

    tree->root = nullptr;
//    tree->size = 0;
    return TREE_NO_ERRORS;
}

size_t nodeCtor(Node *node)
{
    CHECK_NULLPTR_ERROR(node, NODE_IS_NULLPTR)

    node->left = nullptr;
    node->right = nullptr;

    return TREE_NO_ERRORS;
}

size_t treeDtor(Tree *tree)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)

    nodeDtor(tree->root);
//    tree->size = 0;
    return TREE_NO_ERRORS;
}

size_t nodeDtor(Node *node)
{
    CHECK_NULLPTR_ERROR(node, NODE_IS_NULLPTR)

    if (node->left)
        nodeDtor(node->left);
    if (node->right)
        nodeDtor(node->right);

    free(node);
    return TREE_NO_ERRORS;
}

size_t readTree(Tree *tree, const char *filename)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)
    CHECK_NULLPTR_ERROR(filename, STRING_IS_NULLPTR)

    FILE *fp = fopen(filename, "r");
    if (fp == nullptr)
        return CANT_OPEN_TREE_FILE;

    long lenOfFile = 0;
    char *tree_buffer = readFileToBuf(fp, &lenOfFile);
    fclose(fp);

    const char *readPtr = tree_buffer;
    free(tree_buffer);
    return TREE_NO_ERRORS;
}

Node *readRecursiveDescentNode(Tokens *tokens,
                               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    size_t index = 0;
    return recursiveDescent(tokens, &index, name_table);
}

Node *createNewNode(NodeType node_type,
                    NodeValue node_value,
                    Node *left_node,
                    Node *right_node)
{
    Node *node = (Node *) calloc(1, sizeof(node[0]));
    node->left = left_node;
    node->right = right_node;
    node->node_type = node_type;
    node->value = node_value;
    return node;
}

Node *createNum(int value)
{
    Node *node = createNode(NUMBER,
                            {.num_value = value},
                            nullptr,
                            nullptr);
    return node;
}

Node *createNode(NodeType node_type,
                 NodeValue node_value,
                 Node *left_node,
                 Node *right_node)
{
    Node *node = (Node *) calloc(1, sizeof(node[0]));
    LEFT_NODE = left_node;
    RIGHT_NODE = right_node;
    NODE_TYPE = node_type;
    VALUE = node_value;
}