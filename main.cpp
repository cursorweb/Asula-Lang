#include <iostream>
#include <string>

#include "lexer.hpp"


int main() {
    Token token(TType::Plus, Val(5.34));

    std::cout << (int)token.type << " " << token.val.number << std::endl;
    
    std::string string;
    std::cout << "Name: ";
    std::getline(std::cin, string);
    std::cout << "'" << string << "' " << string.length() << std::endl;
}