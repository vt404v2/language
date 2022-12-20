#include "backend.h"

void convertTreeToAsm(const char *tree_filename,
                      const char *asm_filename,
                      const char *asm_func_filename)
{
    assert(tree_filename != nullptr);
    assert(asm_filename != nullptr);
    assert(asm_func_filename != nullptr);

    Tree tree = {};
    treeCtor(&tree);
    readTree(&tree, tree_filename);
    treeDump(&tree);

    FILE *main_fp = fopen(asm_filename, "w");
    FILE *func_fp = fopen(asm_func_filename, "w");

    assemble(&tree, tree.root, main_fp, func_fp);
    treeDtor(&tree);

    if (ftell(func_fp))
        fprintf(main_fp, "\n");
    fclose(func_fp);
    fclose(main_fp);

    char command[BUFFER_SIZE] = "";
    sprintf(command, "cat %s >> %s", asm_func_filename, asm_filename);
    system(command);

    sprintf(command, "rm %s", asm_func_filename);
    system(command);
}

void assemble(Tree *tree,
              Node *node,
              FILE *main_fp,
              FILE *func_fp)
{
    assert(tree != nullptr);
    assert(node != nullptr);
    assert(main_fp != nullptr);
    assert(func_fp != nullptr);

    fprintf(main_fp, "PUSH 9999\n"
                     "POP rax\n");

    assemble_node(tree, node, main_fp, func_fp);

    fprintf(main_fp, "SHOW_RAM\n");
    fprintf(main_fp, "HLT");
}

#define CHECK_NULLPTR_ARGS            \
    {                                 \
        assert((tree) != nullptr);    \
        assert((node) != nullptr);    \
        assert((main_fp) != nullptr); \
        assert((func_fp) != nullptr); \
    }

void assemble_node(Tree *tree,
                   Node *node,
                   FILE *main_fp,
                   FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    switch (NODE_TYPE)
    {
        case FICTIVE_NODE:
            if (LEFT_NODE)
                assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            if (RIGHT_NODE)
                assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            break;
        case VAR_DEC:
            fprintf(main_fp, "PUSH 0\n"
                             "POP [%zu]\n", VALUE.dec_value);
            break;
        case OPERATOR:
            assembleOperator(tree, node, main_fp, func_fp);
            break;
        case NUMBER:
            fprintf(main_fp, "PUSH %d\n", VALUE.num_value);
            break;
        case VARIABLE:
            fprintf(main_fp, "PUSH [%zu]\n", VALUE.var_value);
            break;
        case WHILE:
            assembleWhile(tree, node, main_fp, func_fp);
            break;
        case IF:
            assembleIf(tree, node, main_fp, func_fp);
            break;
        case IF2:
            fprintf(stderr, "GOT IF ACTIONS WITHOUT CONDITION\n");
            break;
        case DEF:
            assembleDef(tree, node, main_fp, func_fp);
            break;
        case CALL:
            assembleCall(tree, node, main_fp, func_fp);
            break;
        case RETURN:
            assembleReturn(tree, node, main_fp, func_fp);
            break;
        case LOCAL_VARIABLE:
            assembleLocalVariable(tree, node, main_fp, func_fp);
            break;
        case ARRAY_DEC:
            assembleArrayDec(tree, node, main_fp, func_fp);
            break;
        case ARRAY:
            assembleArray(tree, node, main_fp, func_fp);
            break;
        case INCORRECT_TYPE:
            fprintf(stderr, "INCORRECT NODE TYPE: %d\n", NODE_TYPE);
            break;
        default:
            fprintf(stderr, "UNKNOWN NODE TYPE: %d\n", NODE_TYPE);
            break;
    }
}

void assembleArrayDec(Tree *tree,
                      Node *node,
                      FILE *main_fp,
                      FILE *func_fp)
{
    // nothing to do
}

void assembleArray(Tree *tree,
                   Node *node,
                   FILE *main_fp,
                   FILE *func_fp)
{
    // push LEFT_NODE
    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
    fprintf(main_fp, "PUSH %zu\n"
                     "ADD\n"
                     "POP rbx\n"
                     "PUSH [rbx]\n", VALUE.var_value);
}

void assembleOperator(Tree *tree,
                      Node *node,
                      FILE *main_fp,
                      FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    switch (VALUE.op_value)
    {
        case ASSIGN_OP:
            assembleAssign(tree, node, main_fp, func_fp);
            break;

#define CASE_OPER(asm_name)                                \
    case (asm_name##_OP):                                  \
    {                                                      \
        assemble_node(tree, LEFT_NODE, main_fp, func_fp);  \
        assemble_node(tree, RIGHT_NODE, main_fp, func_fp); \
        fprintf(main_fp, "%s\n", (#asm_name));             \
        break;                                             \
    }

        CASE_OPER(ADD)
        CASE_OPER(SUB)
        CASE_OPER(MUL)
        CASE_OPER(DIV)
        CASE_OPER(POW)

#undef CASE_OPER

        case INPUT_OP:
            fprintf(main_fp, "IN\n");
            break;
        case SQRT_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "SQRT\n");
            break;
        case SIN_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "SIN\n");
            break;
        case COS_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "COS\n");
            break;
        case OUTPUT_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "OUT\n");
            break;
        case GREATER_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            fprintf(main_fp, "A\n");
            break;
        case BELOW_OP:
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "A\n");
            break;
        case GREATER_EQ_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            fprintf(main_fp, "AE\n");
            break;
        case BELOW_EQ_OP:
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "AE\n");
            break;
        case EQUAL_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            fprintf(main_fp, "E\n");
            break;
        case NOT_EQ_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            fprintf(main_fp, "E\n"
                             "PUSH 0\n"
                             "E\n");
            break;
        case NOT_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n"
                             "E\n"
                             "PUSH 1\n"
                             "E\n");
            break;
        case AND_OP:
        {
            // left_value to bool
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n"
                             "E\n"
                             "PUSH 0\n"
                             "E\n");

            // right_value to bool
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n"
                             "E\n"
                             "PUSH 0\n"
                             "E\n"
                             "MUL\n");
            break;
        }
        case OR_OP:
        {
            // left_value to bool
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n"
                             "E\n"
                             "PUSH 0\n"
                             "E\n");

            // right_value to bool
            assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n"
                             "E\n"
                             "PUSH 0\n"
                             "E\n"
                             "ADD\n");

            // sum to bool
            fprintf(main_fp, "PUSH 0\n"
                             "E\n"
                             "PUSH 0\n"
                             "E\n");
            break;
        }

        case INCORRECT_OP:
            fprintf(stderr, "INCORRECT OPERATOR\n");
            break;
        default:
            fprintf(stderr,
                    "UNKNOWN OPERATOR %d\n",
                    VALUE.op_value);
            break;
    }
}

void assembleAssign(Tree *tree,
                    Node *node,
                    FILE *main_fp,
                    FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
    if (LEFT_TYPE == VARIABLE)
    {
        fprintf(main_fp,
                "POP [%zu]\n"
                "PUSH [%zu]\n",
                LEFT_NODE->value.var_value,
                LEFT_NODE->value.var_value);
    }
    else if (LEFT_TYPE == ARRAY)
    {
        assemble_node(tree, LEFT_NODE->left, main_fp, func_fp);
        fprintf(main_fp,
                "PUSH %zu\n"
                "ADD\n"
                "POP rbx\n"
                "POP [rbx]\n"
                "PUSH [rbx]\n",
                LEFT_NODE->value.var_value);
    }
    else
    {
        size_t index = LEFT_NODE->value.var_value;
        // set rax to rax - index
        fprintf(main_fp, "PUSH rax\n"
                         "PUSH %zu\n"
                         "ADD\n"
                         "POP rax\n", index);

        // assign value and return it to stack
        fprintf(main_fp,
                "POP [rax]\n"
                "PUSH [rax]\n");

        // set rax - index to rax
        fprintf(main_fp, "PUSH rax\n"
                         "PUSH %zu\n"
                         "SUB\n"
                         "POP rax\n", index);
    }
}

void assembleWhile(Tree *tree,
                   Node *node,
                   FILE *main_fp,
                   FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    Node *condition_node = LEFT_NODE;
    Node *code_node = RIGHT_NODE;

    // exit condition
    assemble_node(tree, condition_node, main_fp, func_fp);
    fprintf(main_fp, "PUSH 0\n"
                     "jbe :label_not_cond_%p\n", code_node);

    // code
    fprintf(main_fp, ":label_%p\n", code_node);
    assemble_node(tree, code_node, main_fp, func_fp);

    // continue condition
    assemble_node(tree, condition_node, main_fp, func_fp);
    fprintf(main_fp, "PUSH 0\n"
                     "ja :label_%p\n", code_node);

    // exit pointer
    fprintf(main_fp, ":label_not_cond_%p\n", code_node);
}

void assembleIf(Tree *tree,
                Node *node,
                FILE *main_fp,
                FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    Node *condition_node = LEFT_NODE;
    Node *true_condition_node = RIGHT_NODE->left;
    Node *false_condition_node = RIGHT_NODE->right;

    // condition for false case
    assemble_node(tree, condition_node, main_fp, func_fp);
    fprintf(main_fp, "PUSH 0\n"
                     "jbe :label_%p\n", false_condition_node);

    // true code
    fprintf(main_fp, ":label_%p\n", true_condition_node);
    assemble_node(tree, true_condition_node, main_fp, func_fp);
    fprintf(main_fp, "jmp :label_exit_if_%p\n", node);

    // false code
    fprintf(main_fp, ":label_%p\n", false_condition_node);
    if (false_condition_node)
        assemble_node(tree,
                      false_condition_node,
                      main_fp,
                      func_fp);
    fprintf(main_fp, "jmp :label_exit_if_%p\n", node);

    // exit pointer
    fprintf(main_fp, ":label_exit_if_%p\n", node);
}

void assembleDef(Tree *tree,
                 Node *node,
                 FILE *main_fp,
                 FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    fprintf(func_fp,
            ":func_%s\n",
            tree->func_name_table[VALUE.def_value]);

    // get number of parameters of function
    size_t num_args = 0;
    countNodes(LEFT_NODE, VARIABLE, &num_args);

    // get number of parameters of function + number of local variables
    size_t num_all_vars = num_args;
    countNodes(RIGHT_NODE, VAR_DEC, &num_all_vars);

    // change values of nodes that are parameters of function
    size_t args_counter = 0;
    // search VARIABLE in LEFT_NODE and replace these nodes in RIGHT_NODE
    changeLocalVarsNodesValues(LEFT_NODE,
                               RIGHT_NODE,
                               VARIABLE,
                               &args_counter,
                               num_all_vars);

    tree->func_num_args[VALUE.def_value] = num_all_vars;

    for (size_t i = 0; i < num_args; i++)
    {
        fprintf(func_fp, "PUSH rax\n"
                         "PUSH %zu\n"
                         "SUB\n"
                         "PUSH %zu\n"
                         "ADD\n"
                         "POP rax\n", num_args - 1, i);

        fprintf(func_fp, "POP [rax]\n"
                         "PUSH rax\n"
                         "PUSH %zu\n"
                         "ADD\n"
                         "PUSH %zu\n"
                         "SUB\n"
                         "POP rax\n", num_args - 1, i);
    }
    fprintf(func_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "SUB\n"
                     "POP rax\n", num_all_vars);


    assemble_node(tree, RIGHT_NODE, func_fp, func_fp);
}

void countNodes(Node *node,
                NodeType search_value,
                size_t *index)
{
    assert(node != nullptr);
    assert(index != nullptr);

    if (LEFT_NODE)
        countNodes(LEFT_NODE, search_value, index);
    if (RIGHT_NODE)
        countNodes(RIGHT_NODE, search_value, index);

    if (NODE_TYPE == search_value)
        (*index)++;
}

void changeLocalVarsNodesValues(Node *node,
                                Node *body_node,
                                NodeType search_value,
                                size_t *index,
                                size_t num_variables)
{
    assert(node != nullptr);
    assert(body_node != nullptr);
    assert(index != nullptr);

    if (LEFT_NODE)
        changeLocalVarsNodesValues(LEFT_NODE,
                                   body_node,
                                   search_value,
                                   index,
                                   num_variables);
    if (RIGHT_NODE)
        changeLocalVarsNodesValues(RIGHT_NODE,
                                   body_node,
                                   search_value,
                                   index,
                                   num_variables);

    if (NODE_TYPE == search_value)
    {
        changeLocalVarsNodesValuesInBody(body_node,
                                         VALUE.var_value,
                                         num_variables - *index);
        NODE_TYPE = LOCAL_VARIABLE;
        VALUE.var_value = *index;
        (*index)++;
    }
}

void changeLocalVarsNodesValuesInBody(Node *node,
                                      size_t old_value,
                                      size_t new_value)
{
    if (LEFT_NODE)
        changeLocalVarsNodesValuesInBody(LEFT_NODE,
                                         old_value,
                                         new_value);
    if (RIGHT_NODE)
        changeLocalVarsNodesValuesInBody(RIGHT_NODE,
                                         old_value,
                                         new_value);

    if (NODE_TYPE == VARIABLE && VALUE.var_value == old_value)
    {
        NODE_TYPE = LOCAL_VARIABLE;
        VALUE.var_value = new_value;
    }
}

void assembleCall(Tree *tree,
                  Node *node,
                  FILE *main_fp,
                  FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    size_t num_args = 0;
    size_t func_id = POISONED_SIZE_T;
    bool found = false;
    searchWhereCall(tree->root, node, &found, &func_id);

    size_t last_num_args = 0;
    if (func_id != (size_t) POISONED_SIZE_T)
        last_num_args = tree->func_num_args[func_id];

    pushArgs(tree,
             LEFT_NODE,
             main_fp,
             &num_args,
             last_num_args);

    fprintf(main_fp,
            "call :func_%s\n",
            tree->func_name_table[VALUE.def_value]);
}

void searchWhereCall(Node *nodeSearchIn,
                     Node *node,
                     bool *found,
                     size_t *func_id)
{
    assert(nodeSearchIn != nullptr);
    assert(node != nullptr);
    assert(found != nullptr);
    assert(func_id != nullptr);

    if (*found)
        return;
    if (nodeSearchIn == node)
    {
        *found = true;
        return;
    }
    if (nodeSearchIn->node_type == DEF)
    {
        if (nodeSearchIn->left)
            searchWhereCall(nodeSearchIn->left, node, found, func_id);
        if (nodeSearchIn->right)
            searchWhereCall(nodeSearchIn->right, node, found, func_id);
        if (*found)
            *func_id = nodeSearchIn->value.def_value;
        return;
    }
    if (*found)
        return;
    if (nodeSearchIn->left)
        searchWhereCall(nodeSearchIn->left, node, found, func_id);
    if (*found)
        return;
    if (nodeSearchIn->right)
        searchWhereCall(nodeSearchIn->right, node, found, func_id);
}

void pushArgs(Tree *tree,
              Node *node,
              FILE *fp,
              size_t *new_arg_id,
              size_t last_num_args)
{
    assert(tree != nullptr);
    assert(node != nullptr);
    assert(fp != nullptr);
    assert(new_arg_id != nullptr);

    if (NODE_TYPE == FICTIVE_NODE)
    {
        if (LEFT_NODE)
            pushArgs(tree, LEFT_NODE, fp, new_arg_id, last_num_args);
        if (RIGHT_NODE)
            pushArgs(tree, RIGHT_NODE, fp, new_arg_id, last_num_args);
    }
    else
    {
        assemble_node(tree, node, fp, fp);
        (*new_arg_id)++;
    }
}

void assembleReturn(Tree *tree,
                    Node *node,
                    FILE *main_fp,
                    FILE *func_fp)

{
    assert(tree != nullptr);
    assert(node != nullptr);
    assert(main_fp != nullptr);
    assert(func_fp != nullptr);

    assemble_node(tree, LEFT_NODE, func_fp, func_fp);

    bool found = false;
    size_t func_id = POISONED_SIZE_T;
    searchWhereCall(tree->root, node, &found, &func_id);

    fprintf(func_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "ADD\n"
                     "POP rax\n"
                     "RET\n", tree->func_num_args[func_id]);
}

void assembleLocalVariable(Tree *tree,
                           Node *node,
                           FILE *main_fp,
                           FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    size_t index = VALUE.var_value;

    // set rax to rax - index
    fprintf(main_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "ADD\n"
                     "POP rax\n", index);

    // push value from [rax] stack
    fprintf(main_fp,
            "PUSH [rax]\n");

    // set rax - index to rax
    fprintf(main_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "SUB\n"
                     "POP rax\n", index);
}


