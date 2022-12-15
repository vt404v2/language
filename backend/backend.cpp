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

//    fixArgsInFunctions();
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

void assemble(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
    assert(tree != nullptr);
    assert(node != nullptr);
    assert(main_fp != nullptr);
    assert(func_fp != nullptr);

    fprintf(main_fp, "PUSH 666\n"
                     "POP rax\n");
    // set function args to arg_variable type
    fixArgVars(tree, node);
    // set local args to local_variable type

    treeDump(tree);
//    for (size_t i = 0; i < 16; i++)
//    {
//        auto d= tree->arg_vars_positions;
//        fprintf(stderr, "table[%zu] = %zu\n", i, tree->arg_vars_positions[i]);
//    }
    assemble_node(tree, node, main_fp, func_fp);

    fprintf(main_fp, "HLT");
}

void fixArgVars(Tree *tree, Node *node)
{
    assert(tree != nullptr);
    assert(node != nullptr);

    size_t index = 0;
    if (NODE_TYPE == DEF)
    {
        registerArgs(tree, RIGHT_NODE, LEFT_NODE, &index);
        registerLocalVars(tree, RIGHT_NODE, RIGHT_NODE, &index);
    }
    if (LEFT_NODE)
        fixArgVars(tree, LEFT_NODE);
    if (RIGHT_NODE)
        fixArgVars(tree, RIGHT_NODE);
//    fprintf(stderr, "index: %zu\n", index);
}

void registerArgs(Tree *tree, Node *start_node, Node *node, size_t *index)
{
    assert(tree != nullptr);
    assert(start_node != nullptr);
    assert(node != nullptr);
    assert(index != nullptr);

    if (NODE_TYPE == FICTIVE_NODE)
    {
        if (LEFT_NODE)
            registerArgs(tree, start_node, LEFT_NODE, index);
        if (RIGHT_NODE)
            registerArgs(tree, start_node, RIGHT_NODE, index);
    }

    if (NODE_TYPE == VARIABLE)
    {
        NODE_TYPE = LOCAL_VARIABLE;
    }
    if (NODE_TYPE == LOCAL_VARIABLE)
    {
        tree->arg_vars_positions[VALUE.var_value] = *index;
        fixLocalVarsInBody(start_node, VALUE.var_value);
        (*index)++;
    }
}

void registerLocalVars(Tree *tree, Node *start_node, Node *node, size_t *index)
{
    assert(tree != nullptr);
    assert(start_node != nullptr);
    assert(node != nullptr);
    assert(index != nullptr);

    if (NODE_TYPE == FICTIVE_NODE)
    {
        if (LEFT_NODE)
            registerLocalVars(tree, start_node, LEFT_NODE, index);
        if (RIGHT_NODE)
            registerLocalVars(tree, start_node, RIGHT_NODE, index);
    }

    if (NODE_TYPE == VAR_DEC)
    {
        NODE_TYPE = LOCAL_VARIABLE;
    }
    if (NODE_TYPE == LOCAL_VARIABLE)
    {
//        fprintf(stderr, "assert: %zu\n", tree->arg_vars_positions[VALUE.var_value] == *index);
        tree->arg_vars_positions[VALUE.var_value] = *index;
//        fixLocalVarsInBody(start_node, VALUE.var_value);
        (*index)++;
    }
}

void fixLocalVarsInBody(Node *node, size_t index)
{
    assert(node != nullptr);

    if (LEFT_NODE)
        fixLocalVarsInBody(LEFT_NODE, index);
    if (RIGHT_NODE)
        fixLocalVarsInBody(RIGHT_NODE, index);
    if (NODE_TYPE == VARIABLE && VALUE.var_value == index)
    {
        NODE_TYPE = LOCAL_VARIABLE;
    }
}

#define CHECK_NULLPTR_ARGS            \
    {                                 \
        assert((tree) != nullptr);    \
        assert((node) != nullptr);    \
        assert((main_fp) != nullptr); \
        assert((func_fp) != nullptr); \
    }

void assemble_node(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
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
            compileOperator(tree, node, main_fp, func_fp);
            break;
        case NUMBER:
            fprintf(main_fp, "PUSH %d\n", VALUE.num_value);
            break;
        case VARIABLE:
            fprintf(main_fp, "PUSH [%zu]\n", VALUE.var_value);
            break;
        case WHILE:
            compileWhile(tree, node, main_fp, func_fp);
            break;
        case IF:
            compileIf(tree, node, main_fp, func_fp);
            break;
        case IF2:
            fprintf(stderr, "GOT IF ACTIONS WITHOUT CONDITION\n");
            break;
        case DEF:
            compileDef(tree, node, main_fp, func_fp);
            break;
        case CALL:
            compileCall(tree, node, main_fp, func_fp);
            break;
        case RETURN:
            compileReturn(tree, node, main_fp, func_fp);
            break;
//        case LOCAL_VARIABLE:
//            fprintf(stderr, "local var: %zu\n", VALUE.var_value);
//            break;
        case LOCAL_VARIABLE:
            compileArgVariable(tree, node, main_fp, func_fp);
            break;
        case INCORRECT_TYPE:
            fprintf(stderr, "INCORRECT NODE TYPE: %d\n", NODE_TYPE);
            break;
        default:
            fprintf(stderr, "UNKNOWN NODE TYPE: %d\n", NODE_TYPE);
            break;
    }
}

void compileOperator(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    switch (VALUE.op_value)
    {
        case ASSIGN_OP:
            compileAssign(tree, node, main_fp, func_fp);
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

#undef CASE_OPER

        case INPUT_OP:
            fprintf(main_fp, "IN\n");
            break;
        case SQRT_OP:
            assemble_node(tree, LEFT_NODE, main_fp, func_fp);
            fprintf(main_fp, "SQRT\n");
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

void compileAssign(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
    if (LEFT_NODE->node_type == VARIABLE)
    {
        fprintf(main_fp,
                "POP [%zu]\n"
                "PUSH [%zu]\n",
                LEFT_NODE->value.var_value,
                LEFT_NODE->value.var_value);
    }
    else
    {
        size_t index =
            tree->arg_vars_positions[LEFT_NODE->value.var_value];

        size_t num_args = index;
        size_t arg_index = VALUE.var_value + 1;

        while (num_args
            < tree->arg_vars_positions[arg_index])
        {
            num_args =
                tree->arg_vars_positions[arg_index];
            arg_index++;
        }
        num_args++;
//        fprintf(stderr, "num_args: %zu\n", num_args);
        // set rax to rax + i - n
        fprintf(main_fp, "PUSH rax\n"
                         "PUSH %zu\n"
                         "ADD\n"
                         "PUSH %zu\n"
                         "SUB\n"
                         "POP rax\n", index, num_args);

        fprintf(main_fp,
                "POP [rax]\n"
                "PUSH [rax]\n");

        // set rax + i - n to rax
        fprintf(main_fp, "PUSH rax\n"
                         "PUSH %zu\n"
                         "SUB\n"
                         "PUSH %zu\n"
                         "ADD\n"
                         "POP rax\n", index, num_args);
    }
}

void compileWhile(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
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

void compileIf(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
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

void compileDef(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    fprintf(func_fp,
            ":func_%s\n",
            tree->func_name_table[VALUE.def_value]);

    size_t num_args = 0;
    registerArgs(tree, RIGHT_NODE, LEFT_NODE, &num_args);

    size_t num_all_vars = num_args;
//    fprintf(stderr, "here\n");
    registerLocalVars(tree, RIGHT_NODE, RIGHT_NODE, &num_all_vars);
//    fprintf(stderr, "%zu %zu\n", num_all_vars, num_args);

    tree->func_num_args[VALUE.def_value] = num_all_vars;

    for (size_t i = 0; i < num_args; i++)
    {
        fprintf(func_fp, "PUSH rax\n"
                         "PUSH %zu\n"
                         "ADD\n"
                         "PUSH %zu\n"
                         "SUB\n"
                         "POP rax\n", num_args - 1, i);

        fprintf(func_fp, "POP [rax]\n"
                         "PUSH rax\n"
                         "PUSH %zu\n"
                         "SUB\n"
                         "PUSH %zu\n"
                         "ADD\n"
                         "POP rax\n", num_args - 1, i);
    }
    fprintf(func_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "ADD\n"
                     "POP rax\n", num_all_vars);


    assemble_node(tree, RIGHT_NODE, func_fp, func_fp);
}

void compileCall(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    size_t num_args = 0;
    size_t func_id = -1;
    bool found = false;
    searchWhereCall(tree->root, node, &found, &func_id);

    size_t last_num_args = 0;
    if (func_id != (size_t) -1)
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

void compileReturn(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)

{
    assert(tree != nullptr);
    assert(node != nullptr);
    assert(main_fp != nullptr);
    assert(func_fp != nullptr);

    assemble_node(tree, LEFT_NODE, func_fp, func_fp);

    bool found = false;
    size_t func_id = -1;
    searchWhereCall(tree->root, node, &found, &func_id);

    fprintf(func_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "SUB\n"
                     "POP rax\n"
                     "RET\n", tree->func_num_args[func_id]);
}

void compileArgVariable(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
    CHECK_NULLPTR_ARGS

    size_t index = tree->arg_vars_positions[VALUE.var_value];
    size_t num_args = index;
    size_t arg_index = VALUE.var_value + 1;

    while (num_args < tree->arg_vars_positions[arg_index])
    {
        num_args = tree->arg_vars_positions[arg_index];
        arg_index++;
    }
    num_args++;

    // set rax to rax + i - n
    fprintf(main_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "ADD\n"
                     "PUSH %zu\n"
                     "SUB\n"
                     "POP rax\n"
                     "PUSH [rax]\n", index, num_args);// PUSH[rax + i - n]

    // set rax + i - n to rax
    fprintf(main_fp, "PUSH rax\n"
                     "PUSH %zu\n"
                     "SUB\n"
                     "PUSH %zu\n"
                     "ADD\n"
                     "POP rax\n", index, num_args);
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
