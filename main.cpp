#include <iostream>
#include <string>

#include <fstream>

#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "run/run.hpp"

#include "util/error.hpp"


int main() {
    std::string code;
    
    std::ifstream file("./idea/test/lexer.asu");

    if (file.is_open()) {
        char c;
        while ((c = file.get()) != EOF) {
            code += c;
        }
    } else {
        std::cout << "Couldn't open file" << std::endl;
    }
    
    file.close();;

    Lexer lexer(code, "./idea/test/lexer.asu");

    try {
        std::vector<Token> tokens = lexer.lex();

        for (Token token : tokens) {
            std::cout << Token::to_string(token.type) << ": { l: " << token.lf.line << ", c: " << token.lf.col << " }" << std::endl;
        }
    } catch (Error e) {
        e.show_error();
        return 1;
    }
}