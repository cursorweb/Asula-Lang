#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>

#include "../lexer/token.hpp"
#include "../util/val.hpp"

using std::shared_ptr;


// visitor list
template<typename C>
class ExprVisitor {
public:
    virtual C visit_binary(Binary binary);
    virtual C visit_unary(Unary unary);
    virtual C visit_grouping(Grouping grouping);
    virtual C visit_literal(Literal literal);
};


// expr list
template<typename C>
class Expr {
public:
    virtual C accept(ExprVisitor<C> visitor);
};


// nodes
template<typename C>
class Binary : public Expr {
public:
    shared_ptr<Expr> left;
    Token op;
    shared_ptr<Expr> right;

    Binary(shared_ptr<Expr> left, Token op, shared_ptr<Expr> right) {
        this->left = left;
        this->op = op;
        this->right = right;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_binary(this);
    }
};

template<typename C>
class Unary : public Expr {
public:
    Token op;
    shared_ptr<Expr> right;

    Unary(Token op, shared_ptr<Expr> right) {
        this->op = op;
        this->right = right;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_unary(this);
    }
};

template<typename C>
class Grouping : public Expr {
public:
    shared_ptr<Expr> val;

    Grouping(shared_ptr<Expr> val) {
        this->val = val;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_grouping(this);
    }
};

template<typename C>
class Literal : public Expr {
public:
    Val val;

    Literal(Val val) {
        this->val = val;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_literal(this);
    }
};

#endif