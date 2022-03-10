#include "lexer.hpp"

Lexer::Lexer(std::string code) {
    this->code = code;
    length = code.length();
}

std::vector<Token> Lexer::lex() {
    while (i < length) {
        char c = peek();
        next();

        switch (c) {
            case '+':
                new_token(consume('=') ? TType::PlusEq : TType::Plus);
                break;
            case '-':
                new_token(consume('=') ? TType::MinusEq : TType::Minus);
                break;
            case '*':
                new_token(consume('*') ? TType::TimesEq : TType::Times);
                break;
            case '/':
                new_token(consume('=') ? TType::DivideEq : TType::Divide);
                break;
            case '^':
                new_token(consume('=') ? TType::PowEq : TType::Pow);
                break;

            case '(':
                new_token(TType::LParen);
                break;
            case ')':
                new_token(TType::RParen);
                break;
            
            case '!':
                new_token(consume('=') ? TType::NotEq : TType::Not);
                break;
            case '=':
                new_token(consume('=') ? TType::EqEq : TType::Eq);
                break;
            
            case '<':
                new_token(consume('=') ? TType::LessEq : TType::Less);
                break;
            case '>':
                new_token(consume('=') ? TType::GreaterEq : TType::Greater);
                break;
            
            case '&':
                new_token(TType::And);
                break;
            case '|':
                new_token(TType::Or);
                break;
            
            case '?':
                new_token(TType::Ques);
                break;
            case ':':
                new_token(TType::Col);
                break;
            
            case '$':
                new_token(TType::Dollar);
                break;
            case '.':
                new_token(TType::Dot);
                break;
            case ',':
                new_token(TType::Comma);
                break;
            
            case ' ':
            case '\r':
            case '\n':
                continue;
            
            default:
                
                break;
        }
    }
    
    new_token(TType::TEOF);
    
    return tokens;
}

char Lexer::peek(int n) {
    if (i + n > code.length()) {
        return '\0'; // invalid
    }

    return code[i + n];
}

bool Lexer::consume(char c) {
    if (peek() == c) {
        next();
        return true;
    }

    return false;
}

void Lexer::next() {
    if (code[i] == '\n') line++;

    i++;
    col++;
}

void Lexer::new_token(TType type, Val val) {
    tokens.push_back(Token(type, LineInfo(line, col), val));
}