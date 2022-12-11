#include "backend.h"

void convertTreeToAsm(const char *tree_filename,
                      const char *asm_filename)
{
    Tree tree = {};
    treeCtor(&tree);
    readTree(&tree, tree_filename);
    treeDump(&tree);

    FILE *fp = fopen(asm_filename, "w");
    assemble(&tree, tree.root, fp);
    fclose(fp);

    treeDtor(&tree);
}

void assemble(Tree *tree, Node *node, FILE *fp)
{
    assemble_node(tree, node, fp);
    fprintf(fp, "HLT");
}

void assemble_node(Tree *tree, Node *node, FILE *fp)
{
    switch (NODE_TYPE)
    {
        case FICTIVE_NODE:
            if (LEFT_NODE)
                assemble_node(tree, LEFT_NODE, fp);
            if (RIGHT_NODE)
                assemble_node(tree, RIGHT_NODE, fp);
            break;
        case VAR_DEC:
            fprintf(fp, "PUSH 0\n"
                        "POP [%zu]\n", VALUE.dec_value);
            break;
        case OPERATOR:
        {
            switch (VALUE.op_value)
            {
                case ASSIGN_OP:
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp,
                            "POP [%zu]\n",
                            node->left->value.var_value);
                    fprintf(fp,
                            "PUSH [%zu]\n",
                            node->left->value.var_value);
                    break;
                case ADD_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "ADD\n");
                    break;
                case SUB_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "SUB\n");
                    break;
                case MUL_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "MUL\n");
                    break;
                case DIV_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "DIV\n");
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
                    fprintf(fp, "IN\n");
                    break;
                case OUTPUT_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    fprintf(fp, "OUT\n");
                    break;
                case GREATER_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "A\n");
                    break;
                case BELOW_OP:
                    assemble_node(tree, RIGHT_NODE, fp);
                    assemble_node(tree, LEFT_NODE, fp);
                    fprintf(fp, "A\n");
                    break;
                case GREATER_EQ_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "AE\n");
                    break;
                case BELOW_EQ_OP:
                    assemble_node(tree, RIGHT_NODE, fp);
                    assemble_node(tree, LEFT_NODE, fp);
                    fprintf(fp, "AE\n");
                    break;
                case EQUAL_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "E\n");
                    break;
                case NOT_EQ_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "E\n");
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    break;
                case NOT_OP:
                    assemble_node(tree, LEFT_NODE, fp);
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "PUSH 1\n");
                    fprintf(fp, "E\n");
                    break;
                case AND_OP:
                    // left_value to bool
                    assemble_node(tree, LEFT_NODE, fp);
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    // right_value to bool
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "MUL\n");
                    break;
                case OR_OP:
                    // left_value to bool
                    assemble_node(tree, LEFT_NODE, fp);
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    // right_value to bool
                    assemble_node(tree, RIGHT_NODE, fp);
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "ADD\n");
                    // sum to bool
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
                    fprintf(fp, "PUSH 0\n");
                    fprintf(fp, "E\n");
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
            fprintf(fp, "PUSH %d\n", VALUE.num_value);
            break;
        case VARIABLE:
            fprintf(fp, "PUSH [%zu]\n", VALUE.var_value);
            break;
        case WHILE:
        {
            Node *condition_node = LEFT_NODE;
            Node *code_node = RIGHT_NODE;

            // exit condition
            assemble_node(tree, condition_node, fp);
            fprintf(fp, "PUSH 0\n");
            fprintf(fp, "jbe :label_not_cond_%p\n", code_node);
            // code
            fprintf(fp, ":label_%p\n", code_node);
            assemble_node(tree, code_node, fp);
            // continue condition
            assemble_node(tree, condition_node, fp);
            fprintf(fp, "PUSH 0\n");
            fprintf(fp, "ja :label_%p\n", code_node);
            // exit pointer
            fprintf(fp, ":label_not_cond_%p\n", code_node);
            break;
        }
        case IF:
        {
            Node *condition_node = LEFT_NODE;
            Node *selection_node = RIGHT_NODE;
            Node *true_condition_node = RIGHT_NODE->left;
            Node *false_condition_node = RIGHT_NODE->right;

            // condition for false case
            assemble_node(tree, condition_node, fp);
            fprintf(fp, "PUSH 0\n");
            fprintf(fp, "jbe :label_%p\n", false_condition_node);

            // true code
            fprintf(fp, ":label_%p\n", true_condition_node);
            assemble_node(tree, true_condition_node, fp);
            fprintf(fp, "jmp :label_exit_if_%p\n", node);

            // false code
            fprintf(fp, ":label_%p\n", false_condition_node);
            if (false_condition_node)
                assemble_node(tree, false_condition_node, fp);
            fprintf(fp, "jmp :label_exit_if_%p\n", node);

            // exit pointer
            fprintf(fp, ":label_exit_if_%p\n", node);
            break;
        }
        case IF2:
            fprintf(stderr, "GOT IF ACTIONS WITHOUT CONDITION\n");
            break;
        case DEF:
            // TODO: implement
            break;
        case CALL:
            // TODO: implement
            break;
        case RETURN:
            assemble_node(tree, LEFT_NODE, fp);
            fprintf(fp, "RET\n");
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