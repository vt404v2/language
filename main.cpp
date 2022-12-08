#include "tokenizer.h"

int main()
{
    treeClearGraphLogFile();
    treeSetLogFile();
    char filename[] = "program.txt";
    char name_table[BUFFER_SIZE][BUFFER_SIZE] = {};

    Tokens tokens = {};
    ctorTokens(&tokens, 2);

    tokenize(filename, &name_table, &tokens);
    {
        printf("SIZE: %zu\n", tokens.size);
        for (size_t i = 0; i < tokens.size; i++)
        {
            printf("token %.2zu: Type: %d ",
                   i,
                   tokens.tokens[i].type);
            switch (tokens.tokens[i].type)
            {
                case NUMBER_TOKEN:
                    printf("Value: %d\n", tokens.tokens[i].value.num_value);
                    break;
                case KEYWORD_TOKEN:
                    printf("Table id: %zu\n", tokens.tokens[i].value.id_in_table);
                    break;
                case OPERATOR_TOKEN:
                    printf("Value: %d\n", tokens.tokens[i].value.operation);
                    break;
                case BRACKET_TOKEN:
                    printf("Value: %c\n", tokens.tokens[i].value.bracket);
                    break;
                case SPECIAL_TOKEN:
                    printf("Value: %c\n", tokens.tokens[i].value.special_token);
                    break;
                case INCORRECT_TYPE_TOKEN:
                    printf("Value: INCORRECT VALUE\n");
                    break;

            }
        }
    }
    Tree tree = {};
    treeCtor(&tree);

    tree.root = readRecursiveDescentNode(&tokens, &name_table);
    treeDump(&tree, &name_table);
    treeDtor(&tree);
    dtorTokens(&tokens);
    treeCloseLogFile();

    return 0;
}

// [***] comment
// number_of_variables all variables
// 3
// x
// y
// z
// variables a-z, A-Z, _ UTF-8
// number_of_functions f n %d %d n - number of params
// 2
// f 2 a b
// g 3 a b c
// tree
// fictive element for code order
// { node_type value
// { left_node }
// { right_node }
//
//
//
// { if
//     { cond }
//     { if2
//          { + }
//          { - }
//     }
// }
//
// { while
//     { cond }
//     { fictive
//         { action }
//     }
// }
//
// def f(a, b, c)
// { def
//     { params }
//     { body }
// }
//
// f(a, b, c)
// { call
//     { fictive
//         { a }
//         { fictive
//             { b }
//             { fictive }
//          }
//     }
// }
//
// operators
// 1 +
// 2 -
// 3 *
// 4 /
// 5 pow
// 6 input
// 7 output return output value
// 8 ==
// 9 >
// 10 <
// 11 >=
// 12 <=
// 13 !=
// 14 !
// 15 or
// 16 and
// 17 = return value
//
// node_types
// 0 0       fictive node
// 1 int     number
// 2 size_t  variable ind_in_name_table
// 3 0       if
// 4 0       if2
// 5 0       while
// 6 op_type operator
// 7 size_t  var ind_in_name_table
// 8 size_t  def ind_in_name_table
// 9 size_t  call
//10 0       return