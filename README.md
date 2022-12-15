# My own Turing-complete programming language "Inverted Cringe Python-C" (ICPC)

## Project description

We have our common standard of abstract syntax tree(AST) that represents program on our programming languages.
# TODO: comments

## Standard of file with tree
Tree file contains the following parts
* variable_name_table

n = number of global and local variables
{n lines with global and local variables names}

* function_name_table

m = number of function
{n lines with functions names}

* tree

Every node of tree starts with '{' and ends with '}. 
After '{':
* first value - node_type with data type - size_t
* second value - node_value with data_type size_t or int
* (optional) left and right node if exists

### Node types
* INCORRECT_TYPE   = -1, 
* FICTIVE_NODE     =  0, node for storing code block in its' left nonde
* NUMBER           =  1, node with int number
* VARIABLE         =  2, node with variable id id variable_name_table
* IF               =  3, node represents condition of 'if' operator in its left node and 'IF2' in its right node
* IF2              =  4, node represents positive branch of 'if' operator in its left node and negative branch in in right node
* WHILE            =  5, node represents condition of 'if' operator in its left node and action subtree in its right node
* OPERATOR         =  6, node with operator
* VAR_DEC          =  7, node represents variable declaration
* DEF              =  8, node represents function definition, with id of function in function_name_table, its parameters in left node and its body in right node
* CALL             =  9, node represents function call with its' id in function_name_table, with function argumnets in left node
* RETURN           = 10, 
* LOCAL_VARIABLE   = 11, // not in standard, my own node type

### Supported operator types
* INCORRECT_OP  = -1,
* ADD_OP        =  1,
* SUB_OP        =  2,
* MUL_OP        =  3,
* DIV_OP        =  4,
* SQRT_OP       =  5,
* INPUT_OP      =  6,
* OUTPUT_OP     =  7,
* EQUAL_OP      =  8,
* GREATER_OP    =  9,
* BELOW_OP      = 10,
* GREATER_EQ_OP = 11,
* BELOW_EQ_OP   = 12,
* NOT_EQ_OP     = 13,
* NOT_OP        = 14,
* OR_OP         = 15,
* AND_OP        = 16,
* ASSIGN_OP     = 17

## Project structure

This project contains the following parts:
* Frontend converts code to AST.
* * Lexical analyzer splits code into tokens for syntax analyzer.
* * Syntax analyzer converts tokens to AST.
* Middleend simplifies AST by collapsing constants and deleting neutral elements
* Backend assembles AST to my own assembler language that can be executed on my own processor
* Backfrontend converts AST to my programming language
* Processor emulator of real processor that can execute programs on my assembler language

* ```./backend/``` - code of backend implementation
* ```./backfrontend/``` - code of backfrontend implementation
* ```./common/``` - utils required for all parts of project
* ```./exmaples/``` - code examples what can be compile and run using this language
* ```./executable_files/``` - executable files of project code what can be run on linux
* ```./frontend/``` - code of frontend implementation
* ```./internal/``` - internal folder for storing ASTs, asm and disasm files
* ```./logs/``` - folder with project logs, such as graphical dumps of AST from graphviz
* ```./middleend/``` - code of middleend implementation
* ```./proccesor/``` - code of processor implementation
* ```./tokenizer/``` - code of lexical analyzer implementation
* ```./tree/``` - code of binary tree implementation

## How to run?
* Run any part of project by building and running required target using cmake. For example for running frontend:
```shell
cmake --build . --target frontend_run
executable_files/frontend_run examples/quadratic.txt internal/standard_tree.txt internal/backend_tree.txt
```
* Compile and run your code using:
```shell
cmake --build . --target language_run
./language_run code.txt
```

