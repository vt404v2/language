# My own Turing-complete programming language

## Project description

We have our common standard of abstract syntax tree(AST) that represents program on our programming languages.

//TODO: here standard

This project contains the following parts:
* Frontend converts code to AST.
* * Lexical analyzer splits code into tokens for syntax analyzer.
* * Syntax analyzer converts tokens to AST.
* Middleend simplifies AST by collapsing constants and deleting neutral elements
* Backend assembles AST to my own assembler language that can be executed on my own processor
* Backfrontend converts AST to my programming language
* Processor emulator of real processor that can execute programs on my assembler language

## Project structure

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

