#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "../util/val.hpp"


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
    NotEq,
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

    Token(TType type, LineInfo lf, Val val);
};

#endif