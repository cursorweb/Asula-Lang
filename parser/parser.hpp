#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <memory>
#include <sstream>

#include "nodes/expr.hpp"
#include "nodes/stmt.hpp"
#include "../lexer/token.hpp"
#include "../util/error.hpp"

using std::shared_ptr;

typedef shared_ptr<Expr> expr_p;


class Parser {
    std::vector<Token> tokens;

    size_t i = 0;

    expr_p expr();
    expr_p equality();
    expr_p comparison();
    expr_p add();
    expr_p mult();
    expr_p unary();
    expr_p primary();

    bool consume(TType tok);
    void expect(TType tok, std::string error);

    Token prev();
    Token peek();

    bool is_valid();
    void next();
public:
    Parser(std::vector<Token> tokens);
    shared_ptr<Expr> parse();
};

#endif