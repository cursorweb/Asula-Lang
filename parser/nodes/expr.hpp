#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>

#include "../../lexer/token.hpp"
#include "../../util/val.hpp"

using std::shared_ptr;

#define en_sh(Type) public std::enable_shared_from_this<Type>


class Binary;
class Unary;
class Grouping;
class Literal;


// visitor list
class ExprVisitor {
public:
    virtual Val visit_binary(shared_ptr<Binary> binary);
    virtual Val visit_unary(shared_ptr<Unary> unary);
    virtual Val visit_grouping(shared_ptr<Grouping> grouping);
    virtual Val visit_literal(shared_ptr<Literal> literal);
};


// expr list
class Expr {
public:
    virtual Val accept(ExprVisitor visitor);
};


// nodes
class Binary : public Expr, en_sh(Binary) {
public:
    shared_ptr<Expr> left;
    Token op;
    shared_ptr<Expr> right;

    Binary(shared_ptr<Expr> _left, Token _op, shared_ptr<Expr> _right)
        : left(_left), right(_right), op(_op) {}

    Val accept(ExprVisitor visitor) {
        return visitor.visit_binary(this->shared_from_this());
    }
};

class Unary : public Expr, en_sh(Unary) {
public:
    Token op;
    shared_ptr<Expr> right;

    Unary(Token _op, shared_ptr<Expr> _right)
        : op(_op), right(_right) {}

    Val accept(ExprVisitor visitor) {
        return visitor.visit_unary(this->shared_from_this());
    }
};

class Grouping : public Expr, en_sh(Grouping) {
public:
    shared_ptr<Expr> val;

    Grouping(shared_ptr<Expr> _val)
        : val(_val) {}

    Val accept(ExprVisitor visitor) {
        return visitor.visit_grouping(this->shared_from_this());
    }
};

class Literal : public Expr, en_sh(Literal) {
public:
    Val val;

    Literal(Val _val)
        : val(_val) {}

    Val accept(ExprVisitor visitor) {
        return visitor.visit_literal(this->shared_from_this());
    }
};

#undef en_sh
#endif