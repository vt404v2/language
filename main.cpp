#include "frontend/frontend.h"
#include "backend/backend.h"
#include "backfrontend/backfrontend.h"

//#define test "program.txt"
//#define test "test.txt"
//#define test "fib.txt"
//#define test "quadratic.txt"
#define test "factorial.txt"

int main()
{
    treeClearGraphLogFile();
    treeSetLogFile();

    system("cmake --build . --target frontend_run");
    system("./frontend_run");

    convertProgramToTree(test, "tree.txt");
    convertTreeToAsm("tree.txt", "lang.asm", "func_def.asm");
//    convertTreeToCode("tree.txt", "code.txt");

    system("cmake --build ./processor --target main");
    system("cd processor; ./main");

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