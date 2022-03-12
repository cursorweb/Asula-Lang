#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>

#include "../lexer/token.hpp"


class Parser {
    std::vector<Token> tokens;

public:
    Parser(std::vector<Token> tokens);
    parse();
};

#endif