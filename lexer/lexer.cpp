#include "lexer.hpp"

static std::map<std::string, TType> keywords {
    { "for", TType::For },
    { "while", TType::While },
    { "if", TType::If },
    { "elif", TType::Elif },
    { "else", TType::Else },
    { "true", TType::True },
    { "false", TType::False },
    { "ret", TType::Ret },
    { "def", TType::Def },
    { "var", TType::Var },
    { "class", TType::Class },
    { "end", TType::End },
    { "block", TType::Block },
};

Lexer::Lexer(std::string code, std::string file) {
    this->code = code;
    this->lf.file = file;
    
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
                new_token(consume('=') ? TType::TimesEq : TType::Times);
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

            case '"':
            case '\'': {
                char end = code[i - 1];
                
                std::string string;

                while ((c = peek()) != end && is_valid(c)) {
                    string += c;
                    
                    next();
                }

                if (!consume(end)) {
                    throw Error(lf, "Unterminated string.");
                }

                new_token(TType::String, string);
            } break;
            
            case ' ':
            case '\r':
            case '\n':
                continue;

            case '#':
                while ((c = peek()) != '\n' && is_valid(c)) {
                    next();
                }
                break;
            
            default:
                if (is_alpha(c)) {
                    std::string identifier;
                    identifier += c;

                    while (is_alphanum(c = peek())) {
                        identifier += c;
                        next();
                    }

                    if (keywords.find(identifier) != keywords.end()) {
                        new_token(keywords[identifier]);
                    } else {
                        new_token(TType::Identifier, identifier);
                    }
                } else if (is_num(c)) {
                    std::string num;
                    num += c;
                    
                    c = peek();

                    while (is_num(c) || c == '\'') {
                        if (c == '\'') {
                            next();
                            c = peek();
                            continue;
                        }

                        num += c;

                        next();
                        c = peek();
                    }

                    if (c == '.') {
                        num += '.';

                        next();
                        c = peek();

                        while (is_num(c) || c == '\'') {
                            if (c == '\'') {
                                next();
                                c = peek();
                                continue;
                            }

                            num += c;

                            next();
                            c = peek();
                        }
                    }

                    double f = std::stod(num);

                    new_token(TType::Number, f);
                } else {
                    throw Error(lf, std::string("Unexpected token ") + c);
                }
                break;
        }
    }

    next();
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
    if (peek() == '\n') {
        lf.line++;
        lf.col = 0;
    } else {
        lf.col++;
    }

    i++;
}

bool Lexer::is_alpha(char c) {
    return 'a' <= tolower(c) && tolower(c) <= 'z';
}

bool Lexer::is_num(char c) {
    return '0' <= c && c <= '9';
}

bool Lexer::is_alphanum(char c) {
    return is_alpha(c) || is_num(c);
}

bool Lexer::is_valid(char c) {
    return c != '\0';
}

void Lexer::new_token(TType type, Val val) {
    tokens.push_back(Token(type, LineInfo(lf.line, lf.col), val));
}