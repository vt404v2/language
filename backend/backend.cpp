#include "backend.h"

void convertTreeToAsm(const char *tree_filename,
                      const char *asm_filename,
                      const char *asm_func_filename)
{
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

void assemble(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
    fprintf(main_fp, "PUSH 666\n");
    fprintf(main_fp, "POP rax\n");

    fixArgVars(tree, node);
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
    size_t index = 0;
    if (NODE_TYPE == DEF)
        registerArgs(tree, LEFT_NODE, &index);
    if (LEFT_NODE)
        fixArgVars(tree, LEFT_NODE);
    if (RIGHT_NODE)
        fixArgVars(tree, RIGHT_NODE);
}

void registerArgs(Tree *tree, Node *node, size_t *index)
{
    if (NODE_TYPE == FICTIVE_NODE)
    {
        if (LEFT_NODE)
            registerArgs(tree, LEFT_NODE, index);
        if (RIGHT_NODE)
            registerArgs(tree, RIGHT_NODE, index);
    }
    if (NODE_TYPE == ARG_VARIABLE)
    {
        tree->arg_vars_positions[VALUE.var_value] = *index;
        //        fprintf(stderr, "var_value: %zu index: %zu\n", VALUE.var_value, *index);
        (*index)++;
    }
}

void assemble_node(Tree *tree, Node *node, FILE *main_fp, FILE *func_fp)
{
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
        {
            switch (VALUE.op_value)
            {
                case ASSIGN_OP:
                    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
                    if (LEFT_NODE->node_type == VARIABLE)
                    {
                        fprintf(main_fp,
                                "POP [%zu]\n",
                                node->left->value.var_value);
                        fprintf(main_fp,
                                "PUSH [%zu]\n",
                                node->left->value.var_value);
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

                        // set rax to rax + i - n
                        fprintf(main_fp, "PUSH rax\n");
                        fprintf(main_fp, "PUSH %zu\n", index);
                        fprintf(main_fp, "ADD\n");
                        fprintf(main_fp, "PUSH %zu\n", num_args);
                        fprintf(main_fp, "SUB\n");
                        fprintf(main_fp, "POP rax\n");

                        fprintf(main_fp,
                                "POP [rax]\n");
                        fprintf(main_fp,
                                "PUSH [rax]\n");

                        // set rax + i - n to rax
                        fprintf(main_fp, "PUSH rax\n");
                        fprintf(main_fp, "PUSH %zu\n", index);
                        fprintf(main_fp, "SUB\n");
                        fprintf(main_fp, "PUSH %zu\n", num_args);
                        fprintf(main_fp, "ADD\n");
                        fprintf(main_fp, "POP rax\n");
                    }
                    break;
                case ADD_OP:
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "ADD\n");
                    break;
                case SUB_OP:
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "SUB\n");
                    break;
                case MUL_OP:
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "MUL\n");
                    break;
                case DIV_OP:
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "DIV\n");
                    break;
                case SQRT_OP:
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "SQRT\n");
                    break;
                case INPUT_OP:
                    fprintf(main_fp, "IN\n");
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
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    break;
                case NOT_OP:
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "PUSH 1\n");
                    fprintf(main_fp, "E\n");
                    break;
                case AND_OP:
                {
                    // left_value to bool
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    // right_value to bool
                    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "MUL\n");
                    break;
                }
                case OR_OP:
                {
                    // left_value to bool
                    assemble_node(tree, LEFT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    // right_value to bool
                    assemble_node(tree, RIGHT_NODE, main_fp, func_fp);
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "ADD\n");
                    // sum to bool
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
                    fprintf(main_fp, "PUSH 0\n");
                    fprintf(main_fp, "E\n");
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
            break;
        }
        case NUMBER:
            fprintf(main_fp, "PUSH %d\n", VALUE.num_value);
            break;
        case VARIABLE:
            fprintf(main_fp, "PUSH [%zu]\n", VALUE.var_value);
            break;
        case WHILE:
        {
            Node *condition_node = LEFT_NODE;
            Node *code_node = RIGHT_NODE;

            // exit condition
            assemble_node(tree, condition_node, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n");
            fprintf(main_fp, "jbe :label_not_cond_%p\n", code_node);
            // code
            fprintf(main_fp, ":label_%p\n", code_node);
            assemble_node(tree, code_node, main_fp, func_fp);
            // continue condition
            assemble_node(tree, condition_node, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n");
            fprintf(main_fp, "ja :label_%p\n", code_node);
            // exit pointer
            fprintf(main_fp, ":label_not_cond_%p\n", code_node);
            break;
        }
        case IF:
        {
            Node *condition_node = LEFT_NODE;
            Node *selection_node = RIGHT_NODE;
            Node *true_condition_node = RIGHT_NODE->left;
            Node *false_condition_node = RIGHT_NODE->right;

            // condition for false case
            assemble_node(tree, condition_node, main_fp, func_fp);
            fprintf(main_fp, "PUSH 0\n");
            fprintf(main_fp, "jbe :label_%p\n", false_condition_node);

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
            break;
        }
        case IF2:
            fprintf(stderr, "GOT IF ACTIONS WITHOUT CONDITION\n");
            break;
        case DEF:
        {
            fprintf(func_fp,
                    ":func_%s\n",
                    tree->func_name_table[VALUE.def_value]);
            size_t last_num_args = 0;
            registerArgs(tree, LEFT_NODE, &last_num_args);
            tree->func_num_args[VALUE.def_value] = last_num_args;
            assemble_node(tree, RIGHT_NODE, func_fp, func_fp);
            break;
        }
        case CALL:
        {
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
            break;
        }
        case RETURN:
        {
            assemble_node(tree, LEFT_NODE, func_fp, func_fp);

            bool found = false;
            size_t func_id = -1;
            searchWhereCall(tree->root, node, &found, &func_id);

            fprintf(func_fp, "PUSH rax\n");
            fprintf(func_fp,
                    "PUSH %zu\n",
                    tree->func_num_args[func_id]);
            fprintf(func_fp, "SUB\n");
            fprintf(func_fp, "POP rax\n");

            fprintf(func_fp, "RET\n");
            break;
        }
        case ID_IN_NAME_TABLE:
            fprintf(stderr, "ID_IN_NAME_TABLE NOT SUPPORTED. \n");
            break;
        case ARG_VARIABLE:
        {
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
            fprintf(main_fp, "PUSH rax\n");
            fprintf(main_fp, "PUSH %zu\n", index);
            fprintf(main_fp, "ADD\n");
            fprintf(main_fp, "PUSH %zu\n", num_args);
            fprintf(main_fp, "SUB\n");
            fprintf(main_fp, "POP rax\n");
            fprintf(main_fp, "PUSH [rax]\n");// PUSH[rax + i - n]
            // set rax + i - n to rax
            fprintf(main_fp, "PUSH rax\n");
            fprintf(main_fp, "PUSH %zu\n", index);
            fprintf(main_fp, "SUB\n");
            fprintf(main_fp, "PUSH %zu\n", num_args);
            fprintf(main_fp, "ADD\n");
            fprintf(main_fp, "POP rax\n");
            break;
        }
        case INCORRECT_TYPE:
            fprintf(stderr, "INCORRECT NODE TYPE: %d\n", NODE_TYPE);
            break;
        default:
            fprintf(stderr, "UNKNOWN NODE TYPE: %d\n", NODE_TYPE);
            break;
    }
}

void pushArgs(Tree *tree,
              Node *node,
              FILE *fp,
              size_t *new_arg_id,
              size_t last_num_args)
{
    if (NODE_TYPE == FICTIVE_NODE)
    {
        if (LEFT_NODE)
            pushArgs(tree, LEFT_NODE, fp, new_arg_id, last_num_args);
        if (RIGHT_NODE)
            pushArgs(tree, RIGHT_NODE, fp, new_arg_id, last_num_args);
    }
    if (NODE_TYPE == VARIABLE)
    {
        fprintf(fp, "PUSH [%zu]\n", VALUE.var_value);
        fprintf(fp, "POP [rax]\n");

        fprintf(fp, "PUSH rax\n");
        fprintf(fp, "PUSH 1\n");
        fprintf(fp, "ADD\n");
        fprintf(fp, "POP rax\n");
        (*new_arg_id)++;
    }
    else if (NODE_TYPE == ARG_VARIABLE)
    {
        // set rax to rax + last_arg_position - last_num_args - new_num_args
        fprintf(fp, "PUSH rax\n");
        fprintf(fp,
                "PUSH %zu\n",
                tree->arg_vars_positions[VALUE.var_value]);
        fprintf(fp, "ADD\n");
        fprintf(fp, "PUSH %zu\n", last_num_args);
        fprintf(fp, "SUB\n");
        fprintf(fp, "PUSH %zu\n", *new_arg_id);
        fprintf(fp, "SUB\n");
        fprintf(fp, "POP rax\n");
        // push value from RAM
        fprintf(fp, "PUSH [rax]\n");

        // set rax + last_arg_position - last_num_args - new_num_args to rax
        fprintf(fp, "PUSH rax\n");
        fprintf(fp,
                "PUSH %zu\n",
                tree->arg_vars_positions[VALUE.var_value]);
        fprintf(fp, "SUB\n");
        fprintf(fp, "PUSH %zu\n", last_num_args);
        fprintf(fp, "ADD\n");
        fprintf(fp, "PUSH %zu\n", *new_arg_id);
        fprintf(fp, "ADD\n");
        fprintf(fp, "POP rax\n");

        // put copies of value to RAM
        fprintf(fp, "POP [rax]\n");

        // rax++
        fprintf(fp, "PUSH rax\n");
        fprintf(fp, "PUSH 1\n");
        fprintf(fp, "ADD\n");
        fprintf(fp, "POP rax\n");
        (*new_arg_id)++;
    }
    //    else if (NODE_TYPE == NUMBER)
    //    {
    //        fprintf(fp, "PUSH %d\n", VALUE.num_value);
    ////         put copies of value to RAM
    //        fprintf(fp, "POP [rax]\n");
    ////          rax++
    //        fprintf(fp, "PUSH rax\n");
    //        fprintf(fp, "PUSH 1\n");
    //        fprintf(fp, "ADD\n");
    //        fprintf(fp, "POP rax\n");
    //        (*new_arg_id)++;
    //    }
}

void searchWhereCall(Node *nodeSearchIn,
                     Node *node,
                     bool *found,
                     size_t *func_id)
{
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
        {
            //            fprintf(stderr, "ptr of func %p, call id: %zu\n", nodeSearchIn, nodeSearchIn->value.def_value);
            *func_id = nodeSearchIn->value.def_value;
        }
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