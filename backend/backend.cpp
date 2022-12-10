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
            if (node->left)
                assemble_node(tree, node->left, fp);
            if (node->right)
                assemble_node(tree, node->right, fp);
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
                    assemble_node(tree, node->right, fp);
                    fprintf(fp, "POP [%zu]\n", node->left->value.var_value);
                    fprintf(fp, "PUSH [%zu]\n", node->left->value.var_value);
                    break;
                case ADD_OP:
                    assemble_node(tree, node->left, fp);
                    assemble_node(tree, node->right, fp);
                    fprintf(fp, "ADD\n");
                    break;
                case SUB_OP:
                {
                    assemble_node(tree, node->left, fp);
                    assemble_node(tree, node->right, fp);
                    fprintf(fp, "SUB\n");
                    break;
                }
                case MUL_OP:
                {
                    assemble_node(tree, node->left, fp);
                    assemble_node(tree, node->right, fp);
                    fprintf(fp, "MUL\n");
                    break;
                }
                case DIV_OP:
                {
                    assemble_node(tree, node->left, fp);
                    assemble_node(tree, node->right, fp);
                    fprintf(fp, "DIV\n");
                    break;
                }
                case OUTPUT_OP:
                {
                    assemble_node(tree, node->left, fp);
                    fprintf(fp, "OUT\n");
                    break;
                }
                default:
                {
                    fprintf(stderr, "UNKNOWN OPERATOR\n");
                    break;
                }
            }
            break;
        }
        case NUMBER:
            fprintf(fp, "PUSH %d\n", VALUE.num_value);
            break;
        case VARIABLE:
            fprintf(fp, "PUSH [%zu]\n", VALUE.var_value);
            break;
        default:
            fprintf(stderr, "UNKNOWN NODETYPE: %d\n", NODE_TYPE);
    }
}