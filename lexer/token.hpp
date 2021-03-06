#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "../util/val.hpp"


struct LineInfo {
    size_t line;
    size_t col;

    std::string file;

    LineInfo(size_t line = 0, size_t col = 0, std::string file = "");
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

    Var,
    Class,

    End,
    Block,
    

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

    Token(TType type, LineInfo lf, Val val = Val());

    static std::string to_string(TType type);
};

#endif