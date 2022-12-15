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

    LEFT_NODE = nullptr;
    RIGHT_NODE = nullptr;

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

    if (LEFT_NODE)
        nodeDtor(LEFT_NODE);
    if (RIGHT_NODE)
        nodeDtor(RIGHT_NODE);

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
    LEFT_NODE = left_node;
    RIGHT_NODE = right_node;
    NODE_TYPE = node_type;
    VALUE = node_value;
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
    return node;
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
    assert(node != nullptr);
    assert(name_table != nullptr);
    assert(fp != nullptr);

    size_t var_table[BUFFER_SIZE] = {};
    size_t func_ids_table[BUFFER_SIZE] = {};
    size_t length = 0;
    size_t func_id = -1;

    getVariables(node, &var_table, &func_ids_table, &length, &func_id);

    fprintf(fp, "%zu\n", length);
    for (size_t i = 0; i < length; i++)
        fprintf(fp, "%s\n", (*name_table)[var_table[i]]);


    // change values in nodes with variables,
    // because their indexes were changed
    fixVariables(node, &var_table, &func_ids_table, &length);
}

void fixVariables(Node *node,
                  size_t (*var_table)[BUFFER_SIZE],
                  size_t (*func_ids_table)[BUFFER_SIZE],
                  size_t *length)
{
    assert(node != nullptr);
    assert(var_table != nullptr);
    assert(func_ids_table != nullptr);
    assert(length != nullptr);

    if (NODE_TYPE == VAR_DEC || NODE_TYPE == VARIABLE || NODE_TYPE == LOCAL_VARIABLE)
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
    if (LEFT_NODE)
        fixVariables(LEFT_NODE, var_table, func_ids_table, length);
    if (RIGHT_NODE)
        fixVariables(RIGHT_NODE, var_table, func_ids_table, length);
}

void getVariables(Node *node,
                  size_t (*var_table)[BUFFER_SIZE],
                  size_t (*func_ids_table)[BUFFER_SIZE],
                  size_t *length,
                  size_t *func_id)
{
    assert(node != nullptr);
    assert(var_table != nullptr);
    assert(func_ids_table != nullptr);
    assert(length != nullptr);
    assert(func_id != nullptr);

    if (NODE_TYPE == DEF)
    {
        *func_id = VALUE.def_value;
    }
    if (NODE_TYPE == VAR_DEC || NODE_TYPE == LOCAL_VARIABLE)
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
            (*func_ids_table)[*length] = *func_id;
            (*length)++;
        }
    }
    if (LEFT_NODE)
        getVariables(LEFT_NODE, var_table, func_ids_table, length, func_id);
    if (RIGHT_NODE)
        getVariables(RIGHT_NODE, var_table, func_ids_table, length, func_id);
    if (NODE_TYPE == DEF)
    {
        *func_id = -1;
    }
}

void printFunctions(Node *node,
                    char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                    FILE *fp)
{
    assert(node != nullptr);
    assert(name_table != nullptr);
    assert(fp != nullptr);

    size_t func_table[BUFFER_SIZE] = {};
    size_t length = 0;

    getFunctions(node, &func_table, &length);

    fprintf(fp, "%zu\n", length);
    for (size_t i = 0; i < length; i++)
        fprintf(fp, "%s\n", (*name_table)[func_table[i]]);

    // change values in nodes with functions,
    // because their indexes were changed
    fixFunctions(node, &func_table, &length);
}

void fixFunctions(Node *node,
                  size_t (*func_table)[BUFFER_SIZE],
                  size_t *length)
{
    assert(node != nullptr);
    assert(func_table != nullptr);
    assert(length != nullptr);

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
    if (LEFT_NODE)
        fixFunctions(LEFT_NODE, func_table, length);
    if (RIGHT_NODE)
        fixFunctions(RIGHT_NODE, func_table, length);
}

void getFunctions(Node *node,
                  size_t (*func_table)[BUFFER_SIZE],
                  size_t *length)
{
    assert(node != nullptr);
    assert(func_table != nullptr);
    assert(length != nullptr);

    if (NODE_TYPE == DEF)
    {
        (*func_table)[*length] = VALUE.def_value;
        (*length)++;
    }
    if (LEFT_NODE)
        getFunctions(LEFT_NODE, func_table, length);
    if (RIGHT_NODE)
        getFunctions(RIGHT_NODE, func_table, length);
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
    if (NODE_TYPE == LOCAL_VARIABLE)
        NODE_TYPE = VARIABLE;
    if (LEFT_NODE == nullptr && RIGHT_NODE == nullptr)
    {
        if (NODE_TYPE == NUMBER)
        {
            fprintf(fp,
                    "{ %d  %d }\n",
                    node->node_type,
                    node->value.num_value);
        }
        else
        {
            fprintf(fp,
                    "{ %d  %zu }\n",
                    node->node_type,
                    node->value.call_value);
        }
        return TREE_NO_ERRORS;
    }
    else
        fprintf(fp,
                "{ %d  %zu \n",
                node->node_type,
                node->value.call_value);

    if (LEFT_NODE)
        error = nodePreOrderPrint(LEFT_NODE,
                                  fp,
                                  num_spaces + LOGS_NUM_SPACES);
    if (error)
        return error;

    if (RIGHT_NODE)
        error = nodePreOrderPrint(RIGHT_NODE,
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
    assert(tree != nullptr);
    assert(filename != nullptr);

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
    assert(readPtr != nullptr);
    assert(*readPtr != nullptr);
    assert(tree != nullptr);

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
    assert(readPtr != nullptr);
    assert(*readPtr != nullptr);
    assert(tree != nullptr);

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
    assert(readPtr != nullptr);
    assert(*readPtr != nullptr);

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
    assert(readPtr != nullptr);
    assert(*readPtr != nullptr);

    int node_type = 0;
    int length = 0;
    size_t value = 0;

    assert(isdigit(**readPtr));
    skipSpaces(readPtr);
    sscanf(*readPtr, "%d%n", &node_type, &length);
    (*readPtr) += length;
    skipSpaces(readPtr);

    Node *value_node = nullptr;
    if (node_type == NUMBER)
    {
        int num_value = 0;
        sscanf(*readPtr, "%d%n", &num_value, &length);
        (*readPtr) += length;
        skipSpaces(readPtr);
        value_node = createNode((NodeType) node_type,
                                {.num_value=num_value},
                                nullptr,
                                nullptr);
    }
    else
    {
        sscanf(*readPtr, "%zu%n", &value, &length);
        (*readPtr) += length;
        skipSpaces(readPtr);
        value_node =  createNode((NodeType) node_type,
                                 {.call_value=value},
                                 nullptr,
                                 nullptr);
    }

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