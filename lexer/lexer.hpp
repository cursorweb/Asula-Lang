#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

#include "../util/val.hpp"


class Token;

class Lexer {
    std::string code;

    size_t line;
    size_t col;

    size_t i = 0;
    size_t length;

    std::vector<Token> tokens;

    char peek(int n = 0);
    char next();
public:
    Lexer(std::string code);
    std::vector<Token> lex();
};


struct LineInfo {
    size_t line;
    size_t col;

    LineInfo();
    LineInfo(size_t line, size_t col);
};


enum class TType {
    Plus,
    Minus,
    Times,
    Divide,
    TEOF
};


class Token {
public:
    LineInfo lf;
    TType type;
    Val val;

    Token(TType type, LineInfo lf);
    Token(TType type, LineInfo lf, Val val);
};

#endif