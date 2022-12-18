#ifndef DIFFERENTIATOR__TREE_H
#define DIFFERENTIATOR__TREE_H

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "config.h"
#include "../common/utils.h"
#include "cstring"
#include <cmath>
#include <cctype>

const size_t BUFFER_SIZE = 1024;
const double EXP = exp(1);
const double EPS = 1e-5;
const size_t MAX_WORD_LENGTH = 666;
const size_t POISONED_SIZE_T = -1;

enum TokenType
{
    INCORRECT_TYPE_TOKEN = -1,
    NUMBER_TOKEN         =  1,
    KEYWORD_TOKEN        =  2,
    OPERATOR_TOKEN       =  3,
    BRACKET_TOKEN        =  4,
    SPECIAL_TOKEN        =  5,
};

enum OperationType
{
    INCORRECT_OP  = -1,
    ADD_OP        =  1,
    SUB_OP        =  2,
    MUL_OP        =  3,
    DIV_OP        =  4,
    SQRT_OP       =  5,
    INPUT_OP      =  6,
    OUTPUT_OP     =  7,
    EQUAL_OP      =  8,
    GREATER_OP    =  9,
    BELOW_OP      = 10,
    GREATER_EQ_OP = 11,
    BELOW_EQ_OP   = 12,
    NOT_EQ_OP     = 13,
    NOT_OP        = 14,
    OR_OP         = 15,
    AND_OP        = 16,
    ASSIGN_OP     = 17,
    POW_OP        = 18,
    SIN_OP        = 100,
    COS_OP        = 101,
};

union TokenValue
{
    int num_value;
    size_t id_in_table;
    OperationType operation;
    char bracket;
    char special_token;
};

struct Token_t
{
    TokenType type = INCORRECT_TYPE_TOKEN;
    TokenValue value = {.num_value = 0};
};

struct Tokens
{
    Token_t *tokens = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};

enum NodeType
{
    INCORRECT_TYPE   = -1,
    FICTIVE_NODE     =  0,
    NUMBER           =  1,
    VARIABLE         =  2,
    IF               =  3,
    IF2              =  4,
    WHILE            =  5,
    OPERATOR         =  6,
    VAR_DEC          =  7,
    DEF              =  8,
    CALL             =  9,
    RETURN           = 10,
    LOCAL_VARIABLE   = 11,
};

union NodeValue
{
    int num_value;
    OperationType op_value;
    size_t var_value;
    size_t dec_value;
    size_t def_value;
    size_t call_value;
};

struct Node
{
    NodeType node_type = INCORRECT_TYPE;
    NodeValue value = {.num_value = 0};
    Node *left = nullptr;
    Node *right = nullptr;
};

struct Tree
{
    Node *root = nullptr;
//    size_t arg_vars_positions[BUFFER_SIZE] = {};
    size_t func_num_args[BUFFER_SIZE] = {};
    char var_name_table[BUFFER_SIZE][BUFFER_SIZE] = {};
    char func_name_table[BUFFER_SIZE][BUFFER_SIZE] = {};
};

enum TreeErrors
{
    NO_ERRORS                 = 0,
    TREE_NO_ERRORS            = 0,
    TREE_IS_NULLPTR           = 1,
    NODE_IS_NULLPTR           = 2,
    TREE_FILENAME_IS_NULLPTR  = 3,
    CANT_OPEN_TREE_FILE       = 4,
    TREE_CANT_ALLOCATE_MEMORY = 5,
    TREE_NO_SUCH_ELEMENT      = 6,
    TOO_MANY_ATTEMPTS_TO_READ = 7,
    STRING_IS_NULLPTR         = 8,
    FILE_IS_NULLPTR           = 9,
    CANT_OPEN_FILE            = 10,
};

#include "../tokenizer/tokenizer.h"
#include "recursive_descent.h"

/**
 * @brief constructor of tree
 *
 * @param tree tree to construct
 * @return error code
 */
size_t treeCtor(Tree *tree);

/**
 * @brief constructor of node
 *
 * @param node node to construct
 * @return error code
 */
size_t nodeCtor(Node *node);

/**
 * @brief destructor of tree
 *
 * @param tree tree to destruct
 * @return error code
 */
size_t treeDtor(Tree *tree);

/**
* @brief destructor of node
*
* @param node node to destruct
* @return error code
*/
size_t nodeDtor(Node *node);

/**
 * @brief saves tree to file
 *
 * @param tree tree to save
 * @param fp file for saving
 * @return error code
 */
size_t treeSaveToFile(Tree *tree,
                      char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                      FILE *fp);

void printVariables(Node *node,
                    char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                    FILE *fp);

void fixVariables(Node *node,
                  size_t (*var_table)[BUFFER_SIZE],
                  size_t (*func_ids_table)[BUFFER_SIZE],
                  size_t *length);

void getVariables(Node *node,
                  size_t (*var_table)[BUFFER_SIZE],
                  size_t (*func_ids_table)[BUFFER_SIZE],
                  size_t *length,
                  size_t *func_id);

void printFunctions(Node *node,
                    char (*name_table)[BUFFER_SIZE][BUFFER_SIZE],
                    FILE *fp);

void fixFunctions(Node *node,
                  size_t (*func_table)[BUFFER_SIZE],
                  size_t *length);

void getFunctions(Node *node,
                  size_t (*func_table)[BUFFER_SIZE],
                  size_t *length);
/**
 * @brief prints nodes in preorder in specific format
 *
 * @param node node to print
 * @param fp file to print
 * @param num_spaces number of formatting spaces
 * @return error code
 */
size_t nodePreOrderPrint(Node *node, FILE *fp, size_t num_spaces = 0);

/**
 * @brief prints nodes in inorder
 *
 * @param node node to print
 * @param fp file to print
 * @param num_spaces number of formatting spaces
 * @return error code
 */
size_t nodeInOrderPrint(Node *node, FILE *fp, size_t num_spaces = 0);

/**
 * @brief prints nodes in postorder
 *
 * @param node node to print
 * @param fp file to print
 * @param num_spaces number of formatting spaces
 * @return error code
 */
size_t nodePostOrderPrint(Node *node, FILE *fp, size_t num_spaces = 0);

Node *readRecursiveDescentNode(Tokens *tokens,
                               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE]);

Node *createNewNode(NodeType node_type,
                    NodeValue node_value,
                    Node *left_node,
                    Node *right_node);

Node *createNum(int value);

Node *createNode(NodeType node_type,
                 NodeValue node_value,
                 Node *left_node,
                 Node *right_node);
/**
 * @brief reads tree from file
 *
 * @param tree tree to save data from file
 * @param filename name of file to read
 * @return error code
 */
size_t readTree(Tree *tree, const char *filename);

void parseVariables(char **readPtr, Tree *tree);

void parseFunctions(char **readPtr, Tree *tree);

Node *parseNode(char **readPtr);

Node *getValueNode(char **readPtr);

#define CHECK_NULLPTR_ERROR(value, error) \
    {                                     \
        assert(#value && (int)error);     \
        if (value == nullptr)             \
            return error;                 \
    }

#define VALUE (node->value)
#define VAL_VALUE (VALUE.num_value)
#define OP_VALUE (VALUE.op_value)
#define VAR_VALUE (VALUE.var_value)
#define LEFT_NODE (node->left)
#define RIGHT_NODE (node->right)
#define NODE_TYPE (node->node_type)
#define IS_OP(OPP) (NODE_TYPE == OPERATOR && OP_VALUE == (OPP))
#define IS_NUM_LEFT (LEFT_NODE->node_type == NUMBER)
#define IS_NUM_RIGHT (RIGHT_NODE->node_type == NUMBER)
#define IS_ZERO_LEFT (IS_NUM_LEFT && abs(LEFT_VALUE) < EPS)
#define IS_ZERO_RIGHT (IS_NUM_RIGHT && abs(RIGHT_VALUE) < EPS)
#define IS_ONE_LEFT (IS_NUM_LEFT && abs(LEFT_VALUE - 1) < EPS)
#define IS_ONE_RIGHT (IS_NUM_RIGHT && abs(RIGHT_VALUE - 1) < EPS)
#define LEFT_VALUE (LEFT_NODE->value.num_value)
#define RIGHT_VALUE (RIGHT_NODE->value.num_value)
#define LEFT_TYPE LEFT_NODE->node_type
#define RIGHT_TYPE RIGHT_NODE->node_type
#define IS_LEFT_TYPE(TYPE) ((LEFT_TYPE) == (TYPE))
#define IS_RIGHT_TYPE(TYPE) ((RIGHT_TYPE) == (TYPE))

#endif //DIFFERENTIATOR__TREE_H
