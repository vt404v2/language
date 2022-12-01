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
//    tree->root = readRecursiveDescentNode(&readPtr);
//    tree->root = readNode(&readPtr, &tree_buffer, lenOfFile);
    free(tree_buffer);
    return TREE_NO_ERRORS;
}

Node *readRecursiveDescentNode(Tokens *tokens)
{
    size_t index = 0;
    return recursiveDescent(tokens, &index);
}

Node *readNode(char **readPtr, char **buffer, long lenOfFile)
{
    OperationType op_type = INCORRECT_OP;

    Node *left_node = nullptr;
    Node *right_node = nullptr;
    while (*readPtr < *buffer + lenOfFile)
    {
        if (**readPtr == '(')
        {
            (*readPtr)++;
            Node *new_node = readNode(readPtr, buffer, lenOfFile);
            if (left_node == nullptr)
                left_node = new_node;
            else
            {
                right_node = new_node;
                break;
            }
        }
        else if (**readPtr == ')')
        {
            (*readPtr)++;
        }
        else if (isdigit(**readPtr))
        {
            int len = 0;
            double value = NAN;
            sscanf(*readPtr, "%lf %n", &value, &len);
            // len of value
            (*readPtr) += len;
            // bracket ) after value
            (*readPtr)++;
            Node *new_node = createNewNode(NUMBER,
                                           {.val_value = value},
                                           nullptr,
                                           nullptr);
            return new_node;
        }
        else
        {
            switch (**readPtr)
            {
                case '+':
                    op_type = ADD_OP;
                    (*readPtr)++;
                    break;
                case '-':
                    op_type = SUB_OP;
                    (*readPtr)++;
                    break;
                case '*':
                    op_type = MUL_OP;
                    (*readPtr)++;
                    break;
                case '/':
                    op_type = DIV_OP;
                    (*readPtr)++;
                    break;
                case '^':
                    op_type = POW_OP;
                    (*readPtr)++;
                    break;
                case 'l':
                    op_type = LOG_OP;
                    (*readPtr)++;
                    break;
                case 's':
                    op_type = SIN_OP;
                    (*readPtr)++;
                    break;
                case 'c':
                    op_type = COS_OP;
                    (*readPtr)++;
                    break;
                default:
                    Node *new_node = createNewNode(ID_IN_NAME_TABLE,
                                                   {.var_value = **readPtr},
                                                   nullptr,
                                                   nullptr);
                    (*readPtr)++;
                    // bracket ) after variable
                    (*readPtr)++;
                    return new_node;
            }
        }
    }
    return createNewNode(OPERATION,
                         {.op_value = op_type},
                         left_node,
                         right_node);
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

Node *createNum(double value)
{
    Node *node = createNode(NUMBER,
                            {.val_value = value},
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