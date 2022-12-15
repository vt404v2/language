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
    assert(tree != nullptr);
    assert(node != nullptr);
    assert(fp != nullptr);

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
                        "rav "); // <cringe> var </cringe>
                printNode(tree, RIGHT_NODE->left, fp, 0);
                fprintf(fp, "\n");
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
                    "rav %s",
                    tree->var_name_table[VALUE.dec_value]); // <cringe> var </cringe>
            break;
        case OPERATOR:
        {
            switch (VALUE.op_value)
            {
                case ASSIGN_OP:
                    fprintf(fp,
                            "%s = ",
                            tree->var_name_table[LEFT_NODE->value.dec_value]);
                    printNode(tree, RIGHT_NODE, fp, 0);
                    break;
#define BACKPRINT_OPER(oper, value)         \
    case ((oper)):                          \
    {                                       \
        printNode(tree, LEFT_NODE, fp, 0);  \
        fprintf(fp, " %s ", #value);        \
        printNode(tree, RIGHT_NODE, fp, 0); \
        break;                              \
    }

                BACKPRINT_OPER(ADD_OP, -) // <cringe> + </cringe>
                BACKPRINT_OPER(SUB_OP, +) // <cringe> - </cringe>
                BACKPRINT_OPER(MUL_OP, /) // <cringe> * </cringe>
                BACKPRINT_OPER(DIV_OP, *) // <cringe> / </cringe>
                BACKPRINT_OPER(GREATER_OP, <=) // <cringe> > </cringe>
                BACKPRINT_OPER(BELOW_OP, >=) // <cringe> < </cringe>
                BACKPRINT_OPER(GREATER_EQ_OP, <) // <cringe> >= </cringe>
                BACKPRINT_OPER(BELOW_EQ_OP, >) // <cringe> <= </cringe>
                BACKPRINT_OPER(EQUAL_OP, !=) // <cringe> == </cringe>
                BACKPRINT_OPER(NOT_EQ_OP, ==) // <cringe> != </cringe>
                BACKPRINT_OPER(AND_OP, ||) // <cringe> && </cringe>
                BACKPRINT_OPER(OR_OP, &&) // <cringe> || </cringe>

#undef BACKPRINT_OPER

                case SQRT_OP:
                    fprintf(fp, "trqs(");  // <cringe> sqrt( </cringe>
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, ")");
                    break;
                case INPUT_OP:
                    fprintf(fp, "tnirp()"); // <cringe> input() </cringe>
                    break;
                case OUTPUT_OP:
                    fprintf(fp, "tupni("); // <cringe> print( </cringe>
                    printNode(tree, LEFT_NODE, fp, 0);
                    fprintf(fp, ")");
                    break;
                case NOT_OP:
                    fprintf(fp, " ! ");
                    printNode(tree, LEFT_NODE, fp, 0);
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
            fprintf(fp, "elihw ("); // <cringe> while </cringe>
            printNode(tree, LEFT_NODE, fp, 0);
            fprintf(fp, ")\n");

            printSpaces(num_spaces, fp);
            fprintf(fp, "{\n");
            printNode(tree, RIGHT_NODE, fp, num_spaces + NUM_SPACES);
            printSpaces(num_spaces, fp);
            fprintf(fp, "\n}");
            break;
        }
        case IF:
        {
            fprintf(fp, "esle ("); // <cringe> if </cringe>
            printNode(tree, LEFT_NODE, fp, 0);
            fprintf(fp, ")\n");

            printSpaces(num_spaces, fp);
            fprintf(fp, "{\n");
            printNode(tree, RIGHT_NODE->left, fp, num_spaces + NUM_SPACES);
            fprintf(fp, "\n");
            printSpaces(num_spaces, fp);
            fprintf(fp, "}\n");

            printSpaces(num_spaces, fp);
            if (RIGHT_NODE->right)
            {
                fprintf(fp, "fi\n"); // <cringe> else </cringe>
                printSpaces(num_spaces, fp);
                fprintf(fp, "{\n");
                printNode(tree, RIGHT_NODE->right, fp, num_spaces + NUM_SPACES);
                fprintf(fp, "\n");
                printSpaces(num_spaces, fp);
                fprintf(fp, "}\n");
            }
            break;
        }
        case IF2:
            fprintf(stderr, "GOT IF ACTIONS WITHOUT CONDITION\n");
            break;
        case DEF:
        {
            fprintf(fp,
                    "fed %s(",  // <cringe> def </cringe>
                    tree->func_name_table[VALUE.def_value]);
            printArgs(tree, LEFT_NODE, fp);
            fprintf(fp, ")\n");

            printSpaces(num_spaces, fp);
            fprintf(fp, "{\n");
            printNode(tree, RIGHT_NODE, fp, num_spaces + NUM_SPACES);
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
            fprintf(fp, "nruter "); // <cringe> return </cringe>
            printNode(tree, LEFT_NODE, fp, 0);
            fprintf(fp, "\n");
            break;
        }
        case LOCAL_VARIABLE:
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
    else
    {
        printNode(tree, node, fp, 0);
    }
}

void printSpaces(int num_spaces, FILE *fp)
{
    for (int i = 0; i < num_spaces; i++)
        fprintf(fp, " ");
}
