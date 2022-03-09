#include "lexer.hpp"

Lexer::Lexer(std::string code) {
    this->code = code;
}

std::vector<Token> Lexer::lex() {
    
}


// lineinfo
LineInfo::LineInfo(size_t line, size_t col) {
    this->line = line;
    this->col = col;
}

LineInfo::LineInfo() {
    line = col = 0;
}


// tokens
Token::Token(TType type, LineInfo lf) {
    this->type = type;
    this->lf = lf;
    val = Val();
}

Token::Token(TType type, LineInfo lf, Val val) {
    this->type = type;
    this->lf = lf;
    this->val = val;
}