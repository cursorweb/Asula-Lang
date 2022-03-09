#include "lexer.hpp"




// lineinfo
LineInfo::LineInfo(size_t line, size_t col) {
    this->line = line;
    this->col = col;
}


// tokens
Token::Token(TType type) {
    this->type = type;
    val = Val();
}

Token::Token(TType type, Val val) {
    this->type = type;
    this->val = val;
}