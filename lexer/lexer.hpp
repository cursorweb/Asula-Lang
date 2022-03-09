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
    // operators
    Plus,
    Minus,
    Times,
    Divide,
    Pow,

    // brackets
    LParen,
    RParen,

    // comparisions
    Not,
    EqEq,
    NeEq,
    LessEq,
    GreaterEq,
    Less,
    Greater,

    // Assignment
    Eq,
    PlusEq,
    MinusEq,
    TimesEq,
    DivideEq,
    PowEq,

    // Logic
    And,
    Or,
    Ques,
    Col,

    // Other
    Dollar,
    Dot,
    Comma,

    // Keywords
    For,
    While,

    If,
    Elif,
    Else,

    True,
    False,

    Ret,
    Def,
    

    // Literals
    String,
    Number,
    Identifier,

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