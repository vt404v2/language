#include "middleend.h"

void simplifyTree(const char *input_tree_filename,
                  const char *output_standard_tree_filename)
{
    assert(input_tree_filename != nullptr);
    assert(output_standard_tree_filename != nullptr);

    Tree tree = {};
    treeCtor(&tree);
    readTree(&tree, input_tree_filename);
    treeDump(&tree);

    simplifyNode(tree.root);

    FILE *output_standard_file = fopen(output_standard_tree_filename, "w");

    size_t num_vars = 0;
    while (strcasecmp(tree.var_name_table[num_vars], "") != 0)
    {
        num_vars++;
    }
    fprintf(output_standard_file, "%zu\n", num_vars);
    for (size_t i = 0; i < num_vars; i++)
    {
        fprintf(output_standard_file, "%s\n", tree.var_name_table[i]);
    }

    size_t num_func = 0;
    while (strcasecmp(tree.func_name_table[num_func], "") != 0)
    {
        num_func++;
    }
    fprintf(output_standard_file, "%zu\n", num_func);
    for (size_t i = 0; i < num_func; i++)
    {
        fprintf(output_standard_file, "%s\n", tree.func_name_table[i]);
    }

    nodePreOrderPrint(tree.root, output_standard_file, 0);

    fclose(output_standard_file);

    treeDtor(&tree);
}

void simplifyNode(Node *node)
{
    assert(node != nullptr);

    bool changed = true;
    Tree tree = {};
    treeCtor(&tree);
    tree.root = node;
    while (changed)
    {
        changed = false;
        convConst(node, &changed);

        changed = false;
        deleteNeutralElements(node, &changed);
    }
}

void convConst(Node *node, bool *changed)
{
    assert(node != nullptr);
    assert(changed != nullptr);

    if (LEFT_NODE)
        convConst(LEFT_NODE, changed);
    if (RIGHT_NODE)
        convConst(RIGHT_NODE, changed);

    if (LEFT_NODE == nullptr || RIGHT_NODE == nullptr)
        return;

    if (IS_NUM_LEFT && IS_NUM_RIGHT)
    {
        *changed = true;

#define OPER_SIMPLIFY(name, oper)                   \
    if (IS_OP((name)))                              \
        VAL_VALUE = LEFT_VALUE oper RIGHT_VALUE; \

        OPER_SIMPLIFY(ADD_OP, +)
        else OPER_SIMPLIFY(SUB_OP, -)
        else OPER_SIMPLIFY(MUL_OP, *)
        else OPER_SIMPLIFY(BELOW_OP, <)
        else OPER_SIMPLIFY(EQUAL_OP, ==)
        else OPER_SIMPLIFY(GREATER_OP, >)
        else OPER_SIMPLIFY(GREATER_EQ_OP, >=)
        else OPER_SIMPLIFY(BELOW_EQ_OP, <=)
        else OPER_SIMPLIFY(NOT_EQ_OP, !=)
        else OPER_SIMPLIFY(AND_OP, &&)
        else OPER_SIMPLIFY(OR_OP, ||)
        else if (IS_OP(NOT_OP))
            VAL_VALUE = !LEFT_VALUE;
        else if (IS_OP(INCORRECT_OP))
            VAL_VALUE = 0;
#undef OPER_SIMPLIFY

        nodeDtor(LEFT_NODE);
        nodeDtor(RIGHT_NODE);
        NODE_TYPE = NUMBER;
        LEFT_NODE = nullptr;
        RIGHT_NODE = nullptr;
    }
}

void deleteNeutralElements(Node *node, bool *changed)
{
    assert(node != nullptr);
    assert(changed != nullptr);

    if (LEFT_NODE)
        deleteNeutralElements(LEFT_NODE, changed);
    if (RIGHT_NODE)
        deleteNeutralElements(RIGHT_NODE, changed);

    if (LEFT_NODE == nullptr || RIGHT_NODE == nullptr)
        return;

    // 0 * f(x), 0 / f(x), f(x) * 0
    if ((IS_ZERO_LEFT  && (IS_OP(MUL_OP) ||
                           IS_OP(DIV_OP))) ||
        (IS_ZERO_RIGHT && IS_OP(MUL_OP)))
        changeNodeTypeToNumber(node, 0, changed);
        // f(x) * 1, f(x) / 1, f(x) + 0, f(x) - 0
    else if ((IS_ONE_RIGHT && (
        IS_OP(MUL_OP) ||
        IS_OP(DIV_OP))) ||
        (IS_ZERO_RIGHT && (IS_OP(ADD_OP)||
            IS_OP(SUB_OP))))
        moveNodeUp(node, LEFT_NODE, RIGHT_NODE, changed);
        // 0 + f(x), 1 * f(x)
    else if ((IS_ZERO_LEFT && IS_OP(ADD_OP)) ||
        (IS_ONE_LEFT && IS_OP(MUL_OP)))
        moveNodeUp(node, RIGHT_NODE, LEFT_NODE, changed);
        // 0 - f(x)
    else if (IS_ZERO_LEFT && IS_OP(SUB_OP))
    {
        LEFT_VALUE = -1;
        NODE_TYPE = OPERATOR;
        OP_VALUE = SUB_OP;
        *changed = true;
    }
}

void moveNodeUp(Node *node,
                Node *node_to_up,
                Node *node_to_delete,
                bool *changed)
{
    assert(node != nullptr);
    assert(node_to_up != nullptr);
    assert(node_to_delete != nullptr);
    assert(changed != nullptr);

    nodeDtor(node_to_delete);

    LEFT_NODE = nullptr;
    RIGHT_NODE = nullptr;
    NODE_TYPE = node_to_up->node_type;
    VALUE = node_to_up->value;

    if (node_to_up->left)
        LEFT_NODE = copyNode(node_to_up->left);
    if (node_to_up->right)
        RIGHT_NODE = copyNode(node_to_up->right);

    nodeDtor(node_to_up);
    *changed = true;
}

void changeNodeTypeToNumber(Node *node,
                            int value,
                            bool *changed)
{
    assert(node != nullptr);
    assert(changed != nullptr);

    nodeDtor(LEFT_NODE);
    nodeDtor(RIGHT_NODE);

    NODE_TYPE = NUMBER;
    VAL_VALUE = value;
    LEFT_NODE = nullptr;
    RIGHT_NODE = nullptr;

    *changed = true;
}

Node *copyNode(Node *node)
{
    assert(node != nullptr);

    Node *new_node = (Node *) calloc(1, sizeof(new_node[0]));
    *new_node = *node;

    Node *new_left = nullptr;
    Node *new_right = nullptr;
    if (new_node->left)
        new_left = copyNode(LEFT_NODE);

    if (new_node->right)
        new_right = copyNode(RIGHT_NODE);

    new_node->left = new_left;
    new_node->right = new_right;

    return new_node;
}