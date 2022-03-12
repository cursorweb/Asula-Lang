#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>

#include "../../lexer/token.hpp"
#include "../../util/val.hpp"

using std::shared_ptr;


// visitor list
template<typename C>
class ExprVisitor;


// expr list
template<typename C>
class Expr {
public:
    virtual C accept(ExprVisitor<C> visitor);
};


// nodes
template<typename C>
class Binary : public Expr<C> {
public:
    shared_ptr<Expr<C>> left;
    Token op;
    shared_ptr<Expr<C>> right;

    Binary(shared_ptr<Expr<C>> left, Token op, shared_ptr<Expr<C>> right) {
        this->left = left;
        this->op = op;
        this->right = right;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_binary(this);
    }
};

template<typename C>
class Unary : public Expr<C> {
public:
    Token op;
    shared_ptr<Expr<C>> right;

    Unary(Token op, shared_ptr<Expr<C>> right) {
        this->op = op;
        this->right = right;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_unary(this);
    }
};

template<typename C>
class Grouping : public Expr<C> {
public:
    shared_ptr<Expr<C>> val;

    Grouping(shared_ptr<Expr<C>> val) {
        this->val = val;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_grouping(this);
    }
};

template<typename C>
class Literal : public Expr<C> {
public:
    Val val;

    Literal(Val val) {
        this->val = val;
    }

    C accept(ExprVisitor<C> visitor) {
        visitor.visit_literal(this);
    }
};


// visitor list
template<typename C>
class ExprVisitor {
public:
    virtual C visit_binary(Binary<C> binary);
    virtual C visit_unary(Unary<C> unary);
    virtual C visit_grouping(Grouping<C> grouping);
    virtual C visit_literal(Literal<C> literal);
};

#endif