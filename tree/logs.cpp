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

size_t treeDump(Tree *tree,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)

    char photo_name[128] = "";

    sprintf(photo_name,
            "log_v.%zu.jpg",
            TREE_GRAPH_LOG_VERSION);

    fprintf(TREE_LOG_FILE, "<pre>\n");

    createGraph(tree, photo_name, name_table);
    fprintf(TREE_LOG_FILE, "<img src=%s />\n", photo_name);
    TREE_GRAPH_LOG_VERSION++;
}

size_t createGraph(Tree *tree,
                   const char *photo_name,
                   char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    CHECK_NULLPTR_ERROR(tree, TREE_IS_NULLPTR)
    CHECK_NULLPTR_ERROR(photo_name, TREE_FILENAME_IS_NULLPTR)

    FILE *fp = fopen(GRAPH_FILENAME, "w");
    fprintf(fp, "digraph TREE {\n"
                "    rankdir=TB;\n");

    createGraphNodes(tree->root, fp, name_table);
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

size_t createGraphNodes(Node *node,
                        FILE *fp,
                        char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    if (!node)
        return TREE_NO_ERRORS;

    size_t error = TREE_NO_ERRORS;

    char node_value[BUFFER_SIZE] = "";
    getValueOfNode(node, &node_value, name_table);

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
        error = createGraphNodes(node->left, fp, name_table);
    if (error)
        return error;

    if (node->right)
        error = createGraphNodes(node->right, fp, name_table);
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

void getValueOfNode(const Node *node,
                    char (*node_value)[BUFFER_SIZE],
                    char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    switch (node->node_type)
    {
        case OPERATION:
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
                case POW_OP:
                    *node_value[0] = '^';
                    break;
                case LOG_OP:
                    sprintf(*node_value, "%s", "log");
                    break;
                case SIN_OP:
                    sprintf(*node_value, "%s", "sin");
                    break;
                case COS_OP:
                    sprintf(*node_value, "%s", "cos");
                    break;
                case INCORRECT_OP:
                    *node_value[0] = '?';
                    break;
                default:
                    *node_value[0] = ' ';
                    break;
            }
            break;
        case NUMBER:
            sprintf(*node_value, "%lg", node->value.val_value);
            break;
        case ID_IN_NAME_TABLE:
            sprintf(*node_value, "%s", (*name_table)[node->value.var_value]);
            break;
        case INCORRECT_TYPE:
            sprintf(*node_value, "%s", "INCORRECT_TYPE");
            break;
        default:
            fprintf(stderr, "Unknown type %d", node->node_type);
            break;
    }
}