#include <iostream>
#include <string>

#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "run/run.hpp"


int main() {
    Token token(TType::Plus, LineInfo(), Val(5.34));

    std::cout << (int)token.type << " " << token.val.number << std::endl;
    
    std::string string;
    std::cout << "Name: ";
    std::getline(std::cin, string);
    std::cout << "'" << string << "' " << string.length() << std::endl;
}