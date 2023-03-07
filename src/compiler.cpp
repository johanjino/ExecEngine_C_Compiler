#include <fstream>
#include <iostream>
#include <unistd.h>
#include <iomanip>

#include "cli.h"
#include "ast.hpp"

void compile(std::ostream &w, std::string file)
{
    /*
    w << ".text" << std::endl;
    w << ".globl f" << std::endl;
    w << std::endl;

    w << "f:" << std::endl;
    w << "addi  t0, zero, 0" << std::endl;
    w << "addi  t0, t0,   5" << std::endl;
    w << "add   a0, zero, t0" << std::endl;
    w << "ret" << std::endl;
    */

   // Generates AST
	const Node *program = parseAST(file);

   // extern const Node *parseAST(std::string file);

	// -V enables visualisation
	// Formatting stuff

//PARSE CHECK
    int span = 0;
    program->print(w,span);
    w << std::endl;
    w << "test" << std::endl;

//CODE CHECK
    // w << ".text" << std::endl;
    // w << ".globl f" << std::endl;
    // w << std::endl;

    // Helper helper = Helper();
    // std::map<std::string, std::string> bindings = helper.bindings;
    // program->riscv_asm(w, helper, "", bindings);
    // w << "ret" << std::endl;



}

// TODO: uncomment the below if you're using Flex/Bison.
extern FILE *yyin;

int main(int argc, char **argv)
{
    // Parse CLI arguments, to fetch the values of the source and output files.
    std::string sourcePath = "";
    std::string outputPath = "";
    if (parse_command_line_args(argc, argv, sourcePath, outputPath))
    {
        return 1;
    }

    // TODO: uncomment the below lines if you're using Flex/Bison.
    // This configures Flex to look at sourcePath instead of
    // reading from stdin.
    const char *sourcePath_c = sourcePath.c_str();
    FILE* yyin = fopen(sourcePath_c, "r");
    if (yyin == NULL){
         perror("Could not open source file");
         return 1;
    }

    // Open the output file in truncation mode (to overwrite the contents)
    std::ofstream output;
    output.open(outputPath, std::ios::trunc);

    // Compile the input
    std::cout << "Compiling: " << sourcePath << std::endl;
    compile(output, sourcePath);
    std::cout << "Compiled to: " << outputPath << std::endl;

    output.close();
    return 0;
}
