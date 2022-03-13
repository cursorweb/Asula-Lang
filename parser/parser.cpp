#include "parser.hpp"


Parser::Parser(std::vector<Token> tokens) {
    this->tokens = tokens;
}

expr_p Parser::parse() {
    return expr();
}

expr_p Parser::expr() {
    return equality();
}

expr_p Parser::equality() {
    expr_p left = comparison();

    while (consume(TType::EqEq) || consume(TType::NotEq)) {
        Token op = prev();
        expr_p right = comparison();

        left = expr_p(new Binary(left, op, right));
    }

    return left;
}

expr_p Parser::comparison() {
    expr_p left = add();

    while (consume(TType::Less) || consume(TType::Greater) || consume(TType::LessEq) || consume(TType::GreaterEq)) {
        Token op = prev();
        expr_p right = add();

        left = expr_p(new Binary(left, op, right));
    }

    return left;
}

expr_p Parser::add() {
    expr_p left = mult();

    while (consume(TType::Plus) || consume(TType::Minus)) {
        Token op = prev();
        expr_p right = mult();

        left = expr_p(new Binary(left, op, right));
    }

    return left;
}

expr_p Parser::mult() {
    expr_p left = unary();

    while (consume(TType::Times) || consume(TType::Divide)) {
        Token op = prev();
        expr_p right = unary();

        left = expr_p(new Binary(left, op, right));
    }

    return left;
}

expr_p Parser::unary() {
    if (consume(TType::Not) || consume(TType::Minus) || consume(TType::Plus)) {
        Token op = prev();
        expr_p right = unary();

        return expr_p(new Unary(op, right));
    }

    return primary();
}

expr_p Parser::primary() {
    if (consume(TType::False)) return expr_p(new Literal(false));
    if (consume(TType::True)) return expr_p(new Literal(true));

    if (consume(TType::Number) || consume(TType::String)) return expr_p(new Literal(prev().val));

    if (consume(TType::LParen)) {
        if (consume(TType::RParen)) return expr_p(new Literal(Val()));

        expr_p val = expr();
        expect(TType::RParen, "Expected ')' after grouping.");
    }

    std::stringstream ss;
    Token t = peek();

    ss << "Unexpected token '";
    ss << Token::to_string(t.type);
    ss << "'.";
    
    throw Error(peek().lf, ss.str());
}


// util
bool Parser::consume(TType tok) {
    if (peek().type == tok) {
        next();
        return true;
    }

    return false;
}

void Parser::expect(TType tok, std::string error) {
    if (!consume(tok)) throw Error(peek().lf, error);
}

Token Parser::prev() {
    return tokens[i - 1];
}

Token Parser::peek() {
    return tokens[i];
}

bool Parser::is_valid() {
    return peek().type != TType::TEOF;
}

void Parser::next() {
    if (is_valid()) i++;
}