#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>

#include "nodes/expr.hpp"
#include "nodes/stmt.hpp"
#include "../lexer/token.hpp"


class Parser {
    std::vector<Token> tokens;

public:
    Parser(std::vector<Token> tokens);
    void parse();
};

#endif