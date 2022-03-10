#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

#include "../util/val.hpp"
#include "../util/error.hpp"
#include "token.hpp"


class Lexer {
    std::string code;

    LineInfo lf = LineInfo(1, 1);

    size_t i = 0;
    size_t length;

    std::vector<Token> tokens;

    char peek(int n = 0);
    bool consume(char c);
    void next();

    void new_token(TType type, Val val = Val());

public:
    Lexer(std::string code, std::string file);
    std::vector<Token> lex();
};

#endif