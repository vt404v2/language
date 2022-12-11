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
    assemble_node(tree, node, main_fp, func_fp);
    fprintf(main_fp, "HLT");
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
                    fprintf(main_fp,
                            "POP [%zu]\n",
                            node->left->value.var_value);
                    fprintf(main_fp,
                            "PUSH [%zu]\n",
                            node->left->value.var_value);
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
                case POW_OP:
                    // TODO: implement
                    break;
                case LOG_OP:
                    // TODO: implement
                    break;
                case SIN_OP:
                    // TODO: implement
                    break;
                case COS_OP:
                    // TODO: implement
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
                case OR_OP:
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
                assemble_node(tree, false_condition_node, main_fp, func_fp);
            fprintf(main_fp, "jmp :label_exit_if_%p\n", node);

            // exit pointer
            fprintf(main_fp, ":label_exit_if_%p\n", node);
            break;
        }
        case IF2:
            fprintf(stderr, "GOT IF ACTIONS WITHOUT CONDITION\n");
            break;
        case DEF:
            fprintf(func_fp, ":func_%s\n", tree->func_name_table[VALUE.def_value]);
//            assemble_node(tree, LEFT_NODE, fp);
            assemble_node(tree, RIGHT_NODE, func_fp, func_fp);
            break;
        case CALL:
            fprintf(main_fp, "call :func_%s\n", tree->func_name_table[VALUE.def_value]);
            break;
        case RETURN:
            assemble_node(tree, LEFT_NODE, func_fp, func_fp);
            fprintf(func_fp, "RET\n");
            break;
        case ID_IN_NAME_TABLE:
            fprintf(stderr, "ID_IN_NAME_TABLE NOT SUPPORTED. \n");
            break;
        case INCORRECT_TYPE:
            fprintf(stderr, "INCORRECT NODE TYPE: %d\n", NODE_TYPE);
            break;
        default:
            fprintf(stderr, "UNKNOWN NODE TYPE: %d\n", NODE_TYPE);
            break;
    }
}