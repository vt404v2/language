#include "logs.h"

FILE *TREE_LOG_FILE = stderr;
const char *TREE_GRAPH_LOG_FILENAME = "logs.html";

size_t TREE_GRAPH_LOG_VERSION = 0;

void treeSetLogFile()
{
    FILE *fp = fopen(TREE_GRAPH_LOG_FILENAME, "a");
    if (fp == nullptr)
        return;

    TREE_LOG_FILE = fp;
    setvbuf(TREE_LOG_FILE, nullptr, _IONBF, 0);
}

void treeClearGraphLogFile()
{
    FILE *fp = fopen(TREE_GRAPH_LOG_FILENAME, "w");
    if (fp == nullptr)
        return;
    fclose(fp);
}

void treeCloseLogFile()
{
    if (TREE_LOG_FILE != nullptr)
        fclose(TREE_LOG_FILE);
}

size_t treeDump(Tree *tree)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)

    char photo_name[128] = "";

    sprintf(photo_name,
            "log_v.%zu.jpg",
            TREE_GRAPH_LOG_VERSION);

    fprintf(TREE_LOG_FILE, "<pre>\n");

    createGraph(tree, photo_name);
    fprintf(TREE_LOG_FILE, "<img src=%s />\n", photo_name);
    TREE_GRAPH_LOG_VERSION++;
}

size_t createGraph(Tree *tree,
                   const char *photo_name)
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)
    CHECK_NULLPTR_ERROR(photo_name, TREE_FILENAME_IS_NULLPTR)

    FILE *fp = fopen(GRAPH_FILENAME, "w");
    fprintf(fp, "digraph TREE {\n"
                "    rankdir=TB;\n");

    createGraphNodes(tree, tree->root, fp);
    createGraphEdges(tree->root, fp);

    // close graph with }
    fprintf(fp, "}\n");

    char command[128] = "";
    fclose(fp);
    sprintf(command,
            "dot %s -T jpg -o %s",
            GRAPH_FILENAME,
            photo_name);
    system(command);
    return TREE_NO_ERRORS;
}

size_t createGraphNodes(Tree *tree,
                        Node *node,
                        FILE *fp)
{
    if (!node)
        return TREE_NO_ERRORS;

    size_t error = TREE_NO_ERRORS;

    char node_value[BUFFER_SIZE] = "";
    getValueOfNode(tree, node, &node_value);

    fprintf(fp,
            "    node_%p[shape=\"record\", \n"
            "        color=%s,"
            "        fillcolor=%s, \n"
            "        style=\"rounded, filled\", \n"
            "        label=\"\n"
            "            {%s |\n"
            "            {{LEFT | %p} | {INDEX | %p} | {RIGHT | %p}}}\"]\n",
            node,
            GREEN_COLOR,
            LIGHT_GREEN_COLOR,
            node_value,
            node->left,
            node,
            node->right);

    if (node->left)
        error = createGraphNodes(tree, node->left, fp);
    if (error)
        return error;

    if (node->right)
        error = createGraphNodes(tree, node->right, fp);
    if (error)
        return error;

    return TREE_NO_ERRORS;
}

size_t createGraphEdges(Node *node, FILE *fp)
{
    if (!node)
        return TREE_NO_ERRORS;

    size_t error = TREE_NO_ERRORS;

    if (node->left)
    {
        fprintf(fp,
                "    node_%p->node_%p[color=%s, fontcolor=%s];",
                node,
                node->left,
                PURPLE_COLOR,
                GREEN_COLOR);
        error = createGraphEdges(node->left, fp);
        if (error)
            return error;
    }

    if (node->right)
    {
        fprintf(fp,
                "    node_%p->node_%p[color=%s, fontcolor=%s];",
                node,
                node->right,
                PURPLE_COLOR,
                RED_COLOR);
        error = createGraphEdges(node->right, fp);
        if (error)
            return error;
    }

    return TREE_NO_ERRORS;
}

void getValueOfNode(Tree *tree,
                    const Node *node,
                    char (*node_value)[BUFFER_SIZE])
{
    switch (node->node_type)
    {
        case OPERATOR:
            switch (node->value.op_value)
            {
                case ADD_OP:
                    *node_value[0] = '+';
                    break;
                case SUB_OP:
                    *node_value[0] = '-';
                    break;
                case MUL_OP:
                    *node_value[0] = '*';
                    break;
                case DIV_OP:
                    *node_value[0] = '/';
                    break;
                case SQRT_OP:
                    sprintf(*node_value, "SQRT");
                    break;
                case INPUT_OP:
                    sprintf(*node_value, "INPUT");
                    break;
                case OUTPUT_OP:
                    sprintf(*node_value, "OUTPUT");
                    break;
                case EQUAL_OP:
                    sprintf(*node_value, "==");
                    break;
                case GREATER_OP:
                    sprintf(*node_value, "&gt;");
                    break;
                case BELOW_OP:
                    sprintf(*node_value, "&lt;");
                    break;
                case GREATER_EQ_OP:
                    sprintf(*node_value, "&gt;=");
                    break;
                case BELOW_EQ_OP:
                    sprintf(*node_value, "&lt;=");
                    break;
                case NOT_EQ_OP:
                    sprintf(*node_value, "!=");
                    break;
                case NOT_OP:
                    sprintf(*node_value, "!");
                    break;
                case OR_OP:
                    sprintf(*node_value, "or");
                    break;
                case AND_OP:
                    sprintf(*node_value, "and");
                    break;
                case ASSIGN_OP:
                    sprintf(*node_value, "=");
                    break;
                case INCORRECT_OP:
                    *node_value[0] = '?';
                    break;
                default:
                    *node_value[0] = ' ';
                    break;
            }
            break;
        case FICTIVE_NODE:
            sprintf(*node_value, "FICTIVE_NODE");
            break;
        case NUMBER:
            sprintf(*node_value, "%d", node->value.num_value);
            break;
        case VARIABLE:
            sprintf(*node_value, "VARIABLE '%s'",
                    tree->var_name_table[node->value.var_value]);
            break;
        case LOCAL_VARIABLE:
            sprintf(*node_value, "LOCAL_VARIABLE '%s'",
                    tree->var_name_table[VALUE.var_value]);
            break;
        case IF:
            sprintf(*node_value, "IF OPERATOR");
            break;
        case IF2:
            sprintf(*node_value, "IF ACTIONS");
            break;
        case WHILE:
            sprintf(*node_value, "WHILE operator");
            break;
        case VAR_DEC:
            sprintf(*node_value, "VARIABLE DECLARATION: '%s'",
                    tree->var_name_table[node->value.var_value]);
            break;
        case DEF:
            sprintf(*node_value, "FUNCTION DECLARATION: '%s'",
                    tree->func_name_table[node->value.def_value]);
            break;
        case CALL:
            sprintf(*node_value, "FUNCTION CALL: '%s'",
                    tree->func_name_table[node->value.call_value]);
            break;
        case RETURN:
            sprintf(*node_value, "RETURN FROM FUNC");
            break;
        case INCORRECT_TYPE:
            sprintf(*node_value, "%s", "INCORRECT_TYPE");
            break;
        default:
            fprintf(stderr, "Unknown type %d", node->node_type);
            break;
    }
}