#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

#include "val.hpp"


class Lexer {
public:
    Lexer(std::string code);
    lex();
};


struct LineInfo {
    size_t line;
    size_t col;

    LineInfo(size_t line, size_t col);
};


enum class TType {
    Plus,
    Minus,
    Times,
    Divide,
};


class Token {
public:
    TType type;
    Val val;

    Token(TType type);
    Token(TType type, Val val);
};

#endif