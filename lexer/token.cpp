#include "token.hpp"


// lineinfo
LineInfo::LineInfo(size_t line, size_t col) {
    this->line = line;
    this->col = col;
}

LineInfo::LineInfo() {
    line = col = 0;
}


// tokens
Token::Token(TType type, LineInfo lf, Val val) {
    this->type = type;
    this->lf = lf;
    this->val = val;
}

std::string Token::to_string(TType type) {
    #define tok(k, v) case TType::k: return v;

    switch (type) {
        tok(Plus, "+")
        tok(Minus, "-")
        tok(Times, "*")
        tok(Divide, "/")
        tok(Pow, "^")
        tok(LParen, "(")
        tok(RParen, ")")
        tok(Not, "!")
        tok(EqEq, "==")
        tok(NotEq, "!=")
        tok(LessEq, "<=")
        tok(GreaterEq, ">=")
        tok(Less, "<")
        tok(Greater, ">")
        tok(Eq, "=")
        tok(PlusEq, "+=")
        tok(MinusEq, "-=")
        tok(TimesEq, "*=")
        tok(DivideEq, "/=")
        tok(PowEq, "^=")
        tok(And, "&")
        tok(Or, "|")
        tok(Ques, "?")
        tok(Col, ":")
        tok(Dollar, "$")
        tok(Dot, ".")
        tok(Comma, ",")
        tok(For, "for")
        tok(While, "while")
        tok(If, "if")
        tok(Elif, "elif")
        tok(Else, "else")
        tok(True, "true")
        tok(False, "false")
        tok(Ret, "ret")
        tok(Def, "def")
        tok(String, "string literal")
        tok(Number, "number literal")
        tok(Identifier, "identifier")
        tok(TEOF, "EOF")
    }

    #undef tok
}