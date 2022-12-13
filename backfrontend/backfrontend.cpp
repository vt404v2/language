#include "backfrontend.h"

void convertTreeToCode(const char *tree_filename, const char *code_filename)
{
    Tree tree = {};
    treeCtor(&tree);
    readTree(&tree, tree_filename);
    treeDump(&tree);

    FILE *fp = fopen(code_filename, "w");
    printNode(&tree, tree.root, fp, 0);

    treeDtor(&tree);
}

void printNode(Tree *tree, Node *node, FILE *fp, int num_spaces)
{
    switch (NODE_TYPE)
    {
        case FICTIVE_NODE:
            if (LEFT_NODE &&
                LEFT_TYPE == VAR_DEC &&
                RIGHT_NODE && RIGHT_NODE->left &&
                RIGHT_NODE->left->node_type == OPERATOR &&
                RIGHT_NODE->left->value.op_value == ASSIGN_OP)
            {
                printSpaces(num_spaces, fp);
                fprintf(fp,
                        "var ");
                printNode(tree, RIGHT_NODE->left, fp, 0);
                fprintf(fp, "\n");
//                printSpaces(num_spaces, fp);
                printNode(tree, RIGHT_NODE->right, fp, num_spaces);
                break;
            }
            printSpaces(num_spaces, fp);
            if (LEFT_NODE)
                printNode(tree, LEFT_NODE, fp, num_spaces);
            if (RIGHT_NODE)
            {
                fprintf(fp, "\n");
                printNode(tree, RIGHT_NODE, fp, num_spaces);
            }
            break;
        case VAR_DEC:
            fprintf(fp,
                    "var %s",
                    tree->var_name_table[VALUE.dec_value]);
            break;
        case OPERATOR:
        {
            switch (VALUE.op_value)
            {
                case ASSIGN_OP:
//                    printSpaces(num_spaces, fp);
                    fprintf(fp,
                            "%s = ",
                            tree->var_name_table[LEFT_NODE->value.dec_value]);
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case ADD_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " + ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case SUB_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " - ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case MUL_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " * ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case DIV_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " / ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case SQRT_OP:
                    fprintf(fp, "sqrt(");
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, ")");
                    break;
                case INPUT_OP:
                    fprintf(fp, "input()");
                    break;
                case OUTPUT_OP:
                    fprintf(fp, "print(");
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, ")");
                    break;
                case GREATER_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " > ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case BELOW_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " < ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case GREATER_EQ_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " >= ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case BELOW_EQ_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " <= ");
                    break;
                case EQUAL_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " == ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case NOT_EQ_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " != ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case NOT_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " ! ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case AND_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " && ");
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
                case OR_OP:
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, " || ");
                    printNode(tree, RIGHT_NODE, fp, 0);
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
            fprintf(fp, "%d", VALUE.num_value);
            break;
        case VARIABLE:
            fprintf(fp, "%s", tree->var_name_table[VALUE.var_value]);
            break;
        case WHILE:
        {
            fprintf(fp, "while (");
            printNode(tree, LEFT_NODE, fp, 0);
            fprintf(fp, ")\n");

            printSpaces(num_spaces, fp);
            fprintf(fp, "{\n");
            printNode(tree, RIGHT_NODE, fp, num_spaces + 4);
            printSpaces(num_spaces, fp);
            fprintf(fp, "\n}");
            break;
        }
        case IF:
        {
            fprintf(fp, "if (");
            printNode(tree, LEFT_NODE, fp, 0);
            fprintf(fp, ")\n");

            printSpaces(num_spaces, fp);
            fprintf(fp, "{\n");
            printNode(tree, RIGHT_NODE->left, fp, num_spaces + 4);
            fprintf(fp, "\n");
            printSpaces(num_spaces, fp);
            fprintf(fp, "}\n");

            printSpaces(num_spaces, fp);
            if (RIGHT_NODE->right)
            {
                fprintf(fp, "else\n");
                printSpaces(num_spaces, fp);
                fprintf(fp, "{\n");
                printNode(tree, RIGHT_NODE->right, fp, num_spaces + 4);
                fprintf(fp, "\n");
                printSpaces(num_spaces, fp);
                fprintf(fp, "}");
            }
            break;
        }
        case IF2:
            fprintf(stderr, "GOT IF ACTIONS WITHOUT CONDITION\n");
            break;
        case DEF:
        {
            fprintf(fp,
                    "def %s(",
                    tree->func_name_table[VALUE.def_value]);
            printArgs(tree, LEFT_NODE, fp);
            fprintf(fp, ")\n");

            printSpaces(num_spaces, fp);
            fprintf(fp, "{\n");
            printNode(tree, RIGHT_NODE, fp, num_spaces + 4);
            printSpaces(num_spaces, fp);
            fprintf(fp, "}\n");
            break;
        }
        case CALL:
        {
            fprintf(fp,
                    "%s(",
                    tree->func_name_table[VALUE.call_value]);
            printArgs(tree, LEFT_NODE, fp);
            fprintf(fp, ")");
            break;
        }
        case RETURN:
        {
            fprintf(fp, "return ");
            printNode(tree, LEFT_NODE, fp, 0);
            fprintf(fp, "\n");
            break;
        }
        case ID_IN_NAME_TABLE:
            fprintf(stderr, "ID_IN_NAME_TABLE NOT SUPPORTED. \n");
            break;
        case ARG_VARIABLE:
        {
            fprintf(fp, "%s", tree->var_name_table[VALUE.var_value]);
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

void printArgs(Tree *tree, Node *node, FILE *fp)
{
    if (NODE_TYPE == FICTIVE_NODE)
    {
        if (LEFT_NODE)
            printArgs(tree, LEFT_NODE, fp);
        if (RIGHT_NODE)
        {
            if (RIGHT_NODE->right)
            {
                fprintf(fp, ", ");
            }
            printArgs(tree, RIGHT_NODE, fp);
        }
    }
    else if (NODE_TYPE == VARIABLE || NODE_TYPE == ARG_VARIABLE)
    {
        fprintf(fp, "%s", tree->var_name_table[VALUE.var_value]);
    }
    else
        fprintf(stderr, "%d\n", NODE_TYPE);
}

void printSpaces(int num_spaces, FILE *fp)
{
    for (int i = 0; i < num_spaces; i++)
        fprintf(fp, " ");
}
