ExecEngine C Compiler
==============================

![logo](admin/ExecEngine.png)

This repo contains the source code for the ANSI C (C90) to RISC-V compiler developed as part of the EIE 2nd Year Instruction Set Architecture and Compilers coursework completed in Spring 2021. This project was done by myself (Johan) and @alvi-codes (Alvi). Our primary road-map and direction was driven by the [**spec**](admin/c_compiler.md). This repo can be used a reference or guideline to learn basics of compiler design such as lexing, parsing, abstract-syntax-tree (AST) and assembly generation. Further, contexts like register allocation, stack pointer, memory management, etc can also be seen. Future works out of the scope of the project, which have not be implemented include intermediate representation and code optimisation. Please note, **copying this code will be consider as plagiarism**.

This project scored a 80% out of all the seen and unseen test cases, putting out compiler second-best ranked among all. The test cases varied from functions and datatypes to pointers and structs. If you have any questions and suggestions, please feel free to reach out to me or open an issue. I would be more than happy to help and learn more 😀.


Overview
--------
Our compiler can be built by calling `make bin/c_compiler` (or just `make`), and must be invoked as follows:

    bin/c_compiler -S <source-file.c> -o <dest-file.s>

The command-line parameters must be provided in the order outlined above mostly which has been derived from the given spec. 

admin
-----
This directory contains admin related images and markdown files, including the specifications of the project. This directory also contains a review of our compiler given by our TA @simon-staal (Simon Staal), which clearly outlines the strengths and weaknesses of our compiler.


compiler_tests
--------------
This folder contains a set of test cases we used to evaluate the functional correctness of our compiler. Most of these were pre-included as part of the spec, but many have been added ourselves which can be found in [**Custom_Tests**](compiler_tests/_custom) to further test specific edge cases and undefined behaviour during development. Each test case has accompanying driver code with which it is tested, where the driver code should always return 0.


include
-------
This directory contains all the header files for our compiler, including the nodes used to develop our [**AST**](include/ast) which we use to generate our assembly, as well as other [*helper functions*](include/ast/ast_helper.hpp) which were used for various purposes such as register allocation, memory management, stack pointer, etc. The base class for our AST is [*node*](include/ast/ast_node.hpp), and all of our other AST constructs was build off it. Each of the different set of constructs has been segregated to different folders to allow better readability and modularity.


src
---
This directory contains the source code for our [*parser*](src/parser.y) written in Yacc and accompanying [*lexer*](src/lexer.flex) written in flex, which are used to initially process the input source code and generate the AST. [*compiler.cpp*](src/compiler.cpp) contains the source code for our actual compiler, and mostly contains any directives needed at the start of the assembly code, as well as some formatting for visualisation.




Acknowledgements
----------------

* Special thanks to [John Wickerson](https://johnwickerson.github.io/) for creating such a wonderful coursework and teaching us Compilers for 2nd Year EIE. 

* Extra-special thanks to @Jpnock (James Nock) and @simon-staal (Simon Staal) for guiding us through this project and reviewing our work with great effort to help us improve!