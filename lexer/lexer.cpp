#include "lexer.hpp"

Lexer::Lexer(std::string code) {
    this->code = code;
    length = code.length();
}

std::vector<Token> Lexer::lex() {
    while (i < length) {
        char c = peek();

        switch (c) {
            case '+':
                break;
        }
    }
    
    tokens.push_back(Token(TType::TEOF, LineInfo(line, col)));
    
    return tokens;
}

char Lexer::peek(int n) {
    if (i + n > code.length()) {
        return '\0'; // invalid
    }

    return code[i + n];
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
