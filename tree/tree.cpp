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

size_t treeSaveToFile(Tree *tree,
                      char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                      FILE *fp)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)

    printVariables(tree->root, name_table, fp);
    printFunctions(tree->root, name_table, fp);

    return nodePreOrderPrint(tree->root, fp, 0);
}

void printVariables(Node *node,
                    char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                    FILE *fp)
{
    size_t var_table[BUFFER_SIZE] = {};
    size_t length = 0;
    getVariables(node, &var_table, &length);
    fprintf(fp, "%zu\n", length);
    for (size_t i = 0; i < length; i++)
    {
        fprintf(fp, "%s\n", (*name_table)[var_table[i]]);
    }
    fixVariables(node, &var_table, &length);
}

void fixVariables(Node *node,
                  size_t (*var_table)[BUFFER_SIZE],
                  size_t *length)
{
    if (NODE_TYPE == VAR_DEC || NODE_TYPE == VARIABLE)
    {
        for (size_t i = 0; i < *length; i++)
        {
            if (VALUE.var_value == (*var_table)[i])
            {
                VALUE.var_value = i;
                break;
            }
        }
    }
    if (node->left)
        fixVariables(node->left, var_table, length);
    if (node->right)
        fixVariables(node->right, var_table, length);
}

void getVariables(Node *node,
                  size_t (*var_table)[BUFFER_SIZE],
                  size_t *length)
{
    if (NODE_TYPE == VAR_DEC || NODE_TYPE == VARIABLE)
    {
        bool exist = false;
        for (size_t i = 0; i < *length; i++)
        {
            if ((*var_table)[i] == VALUE.var_value)
                exist = true;
        }
        if (!exist)
        {
            (*var_table)[*length] = VALUE.var_value;
            (*length)++;
        }
    }
    if (node->left)
        getVariables(node->left, var_table, length);
    if (node->right)
        getVariables(node->right, var_table, length);
}

void printFunctions(Node *node,
                    char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                    FILE *fp)
{
    size_t func_table[BUFFER_SIZE] = {};
    size_t length = 0;
    getFunctions(node, &func_table, &length);
    fprintf(fp, "%zu\n", length);
    for (size_t i = 0; i < length; i++)
    {
        fprintf(fp, "%s\n", (*name_table)[func_table[i]]);
    }
    fixFunctions(node, &func_table, &length);
}

void fixFunctions(Node *node,
                  size_t (*func_table)[BUFFER_SIZE],
                  size_t *length)
{
    if (NODE_TYPE == DEF || NODE_TYPE == CALL)
    {
        for (size_t i = 0; i < *length; i++)
        {
            if (VALUE.call_value == (*func_table)[i])
            {
                VALUE.call_value = i;
                break;
            }
        }
    }
    if (node->left)
        fixFunctions(node->left, func_table, length);
    if (node->right)
        fixFunctions(node->right, func_table, length);
}

void getFunctions(Node *node,
                  size_t (*func_table)[BUFFER_SIZE],
                  size_t *length)
{
    if (NODE_TYPE == DEF)
    {
        (*func_table)[*length] = VALUE.def_value;
        (*length)++;
    }
    if (node->left)
        getFunctions(node->left, func_table, length);
    if (node->right)
        getFunctions(node->right, func_table, length);
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
        fprintf(fp,
                "{ %d  %zu }\n",
                node->node_type,
                node->value.call_value);
        return TREE_NO_ERRORS;
    }
    else
        fprintf(fp,
                "{ %d  %zu \n",
                node->node_type,
                node->value.call_value);

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
    parseVariables(&readPtr, tree);
    parseFunctions(&readPtr, tree);
    tree->root = parseNode(&readPtr);

    return TREE_NO_ERRORS;
}

void parseVariables(char **readPtr, Tree *tree)
{
    size_t num_variables = 0;
    int length = 0;
    sscanf(*readPtr, "%zu%n", &num_variables, &length);
    (*readPtr) += length;
    skipSpaces(readPtr);
    for (size_t i = 0; i < num_variables; i++)
    {
        size_t word_length = 0;
        getWord(readPtr, tree->var_name_table[i], &word_length);
        skipSpaces(readPtr);
    }
}

void parseFunctions(char **readPtr, Tree *tree)
{
    size_t num_functions = 0;
    int length = 0;
    sscanf(*readPtr, "%zu%n", &num_functions, &length);
    (*readPtr) += length;
    skipSpaces(readPtr);
    for (size_t i = 0; i < num_functions; i++)
    {
        size_t word_length = 0;
        getWord(readPtr, tree->func_name_table[i], &word_length);
        skipSpaces(readPtr);
    }
}

Node *parseNode(char **readPtr)
{
    skipSpaces(readPtr);

    if (**readPtr == '{')
    {
        (*readPtr)++;
        skipSpaces(readPtr);
        Node *node = getValueNode(readPtr);
        if (**readPtr == '}')
        {
            (*readPtr)++;
            skipSpaces(readPtr);
            return node;
        }
    }

    return nullptr;
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
    Node *value_node =  createNode((NodeType) node_type,
                                  {.call_value=value},
                                  nullptr,
                                  nullptr);
    if (**readPtr == '}')
    {
        return value_node;
    }
    else
    {
        Node *left = parseNode(readPtr);
        Node *right = parseNode(readPtr);
        value_node->left = left;
        value_node->right = right;
        return value_node;
    }
}