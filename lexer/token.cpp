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