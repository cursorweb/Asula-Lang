#include <iostream>
#include <string>

#include <fstream>

#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "run/run.hpp"

#include "util/error.hpp"

std::string read_file(char* file);


int main(int argc, char** argv) {
    if (argc != 2) {
        // todo: repl?
        std::cout << "Usage: asula <file>" << std::endl;
        return 1;
    }


    // file reader
    char* dir = argv[1];
    std::string code;

    try {
        code = read_file(dir);
    } catch(...) { return 1; }

    
    // lexer
    Lexer lexer(code, dir);
    std::vector<Token> tokens;

    try {
        tokens = lexer.lex();
    } catch (Error e) {
        e.show_error();
        return 1;
    }


    // parser


    // interpreter
}

std::string read_file(char* dir) {
    std::string out;
    std::ifstream file(dir);

    if (file.is_open()) {
        char c;
        while ((c = file.get()) != EOF) {
            out += c;
        }
    } else {
        std::cout << "Couldn't open file '" << dir << "'." << std::endl;
        throw;
    }
    
    file.close();

    return out;
}