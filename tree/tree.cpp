#include "tree.h"

size_t treeCtor(Tree *tree)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)

    tree->root = nullptr;
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

size_t treeSaveToFile(Tree *tree, FILE *fp)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)

    return nodePreOrderPrint(tree->root, fp, 0);
}

size_t nodePreOrderPrint(Node *node, FILE *fp, size_t num_spaces)
{
    CHECK_NULLPTR_ERROR(node, NODE_IS_NULLPTR)
    CHECK_NULLPTR_ERROR(fp, FILE_IS_NULLPTR)

    size_t error = TREE_NO_ERRORS;

    for (size_t i = 0; i < num_spaces; i++)
    {
        fprintf(fp, " ");
    }

    if (node->left == nullptr and node->right == nullptr)
    {
        fprintf(fp, "{ %d  %zu }\n", node->node_type, node->value.call_value);
        return TREE_NO_ERRORS;
    }
    else
        fprintf(fp, "{ %d  %zu \n", node->node_type, node->value.call_value);

    if (node->left)
        error = nodePreOrderPrint(node->left,
                                  fp,
                                  num_spaces + LOGS_NUM_SPACES);
    if (error)
        return error;

    if (node->right)
        error = nodePreOrderPrint(node->right,
                                  fp,
                                  num_spaces + LOGS_NUM_SPACES);
    if (error)
        return error;

    for (size_t i = 0; i < num_spaces; i++)
    {
        fprintf(fp, " ");
    }
    fprintf(fp, "}\n");

    return TREE_NO_ERRORS;
}

size_t readTree(Tree *tree, const char *filename)
{

    FILE *fp = fopen(filename, "r");
    if (fp == nullptr)
        return CANT_OPEN_TREE_FILE;

    long lenOfFile = 0;
    char *tree_buffer = readFileToBuf(fp, &lenOfFile);
    fclose(fp);

    char *readPtr = tree_buffer;

    tree->root = parseNode(&readPtr);

    return TREE_NO_ERRORS;
}

Node *parseNode(char **readPtr)
{

    Node *value_node = nullptr;

    skipSpaces(readPtr);
    if (**readPtr == '{')
    {
        (*readPtr)++;
        skipSpaces(readPtr);
        value_node = getValueNode(readPtr);
    }
    skipSpaces(readPtr);
    if (**readPtr == '}')
    {
        (*readPtr)++;
        skipSpaces(readPtr);
        return value_node;
    }

    Node *left_node = nullptr;
    Node *right_node = nullptr;
    if (**readPtr == '{')
    {
        left_node = parseNode(readPtr);
        if (**readPtr == '}')
            (*readPtr)++;
        skipSpaces(readPtr);
    }

    if (**readPtr == '{')
    {
        right_node = parseNode(readPtr);
        if (**readPtr == '}')
            (*readPtr)++;
        skipSpaces(readPtr);
    }

    value_node->left = left_node;
    value_node->right = right_node;
    return value_node;
}

Node *getValueNode(char **readPtr)
{
    int node_type = 0;
    int length = 0;
    size_t value = 0;

    assert(isdigit(**readPtr));
    skipSpaces(readPtr);
    sscanf(*readPtr, "%d%n", &node_type, &length);
    (*readPtr) += length;
    skipSpaces(readPtr);

    skipSpaces(readPtr);
    sscanf(*readPtr, "%zu%n", &value, &length);
    (*readPtr) += length;
    skipSpaces(readPtr);
    return createNode((NodeType)node_type, {.call_value=value}, nullptr, nullptr);
}