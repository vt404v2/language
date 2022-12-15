#include <stdlib.h>
#include "stdio.h"

void convertStandardTreeToBackendTree()
{
    system("cmake --build . --target backfrontend_run");
    system("executable_files/backfrontend_run internal/standard_tree.txt examples/code.txt");

    system("cmake --build . --target frontend_run");
    system("executable_files/frontend_run examples/code.txt internal/standard_tree.txt internal/backend_tree.txt");
}


//#define code_file "examples/program.txt"
//#define code_file "examples/test.txt"
//#define code_file "examples/fib.txt"
#define code_file "examples/quadratic.txt"
//#define code_file "examples/factorial.txt"


int main(int argc, char *argv[])
{
    system("cmake --build . --target frontend_run");
    if (argc == 2)
    {
        const char *code_filename = argv[1];
        char command[1024] = "";
        sprintf(command,
                "executable_files/frontend_run %s "
                "internal/standard_tree.txt internal/backend_tree.txt",
                code_filename);
    }
    else
    {
        system("executable_files/frontend_run " code_file " internal/standard_tree.txt internal/backend_tree.txt");
    }

    system("cmake --build . --target backfrontend_run");
    system("executable_files/backfrontend_run internal/standard_tree.txt examples/code.txt");

    system("cmake --build . --target middleend_run");
    system("executable_files/middleend_run internal/standard_tree.txt internal/standard_tree.txt");

    convertStandardTreeToBackendTree();

    system("cmake --build . --target backend_run");
    system("executable_files/backend_run internal/backend_tree.txt internal/lang.asm internal/func_def.asm");

    system("cmake --build ./processor --target main");
    system("cd processor; ./main");

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