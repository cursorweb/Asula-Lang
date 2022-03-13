#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>

#include "../../lexer/token.hpp"
#include "../../util/val.hpp"

using std::shared_ptr;

#define expr_p shared_ptr<Expr<C>>
#define en_sh(Type) public std::enable_shared_from_this<Type<C>>


// visitor list
template <typename C>
class ExprVisitor;


// expr list
template <typename C>
class Expr {
public:
    virtual Val accept(ExprVisitor<C> visitor);
};


// nodes
template <typename C>
class Binary : public Expr<C>, en_sh(Binary) {
public:
    expr_p left;
    Token op;
    expr_p right;

    Binary(expr_p _left, Token _op, expr_p _right)
        : left(_left), right(_right), op(_op) {}

    Val accept(ExprVisitor<C> visitor) {
        return visitor.visit_binary(this->shared_from_this());
    }
};

template <typename C>
class Unary : public Expr<C>, en_sh(Unary) {
public:
    Token op;
    expr_p right;

    Unary(Token _op, expr_p _right)
        : op(_op), right(_right) {}

    Val accept(ExprVisitor<C> visitor) {
        return visitor.visit_unary(this->shared_from_this());
    }
};

template <typename C>
class Grouping : public Expr<C>, en_sh(Grouping) {
public:
    expr_p val;

    Grouping(expr_p _val)
        : val(_val) {}

    Val accept(ExprVisitor<C> visitor) {
        return visitor.visit_grouping(this->shared_from_this());
    }
};

template <typename C>
class Literal : public Expr<C>, en_sh(Literal) {
public:
    Val val;

    Literal(Val _val)
        : val(_val) {}

    Val accept(ExprVisitor<C> visitor) {
        return visitor.visit_literal(this->shared_from_this());
    }
};


// visitor list
template <typename C>
class ExprVisitor {
public:
    virtual Val visit_binary(shared_ptr<Binary<C>> binary);
    virtual Val visit_unary(shared_ptr<Unary<C>> unary);
    virtual Val visit_grouping(shared_ptr<Grouping<C>> grouping);
    virtual Val visit_literal(shared_ptr<Literal<C>> literal);
};

#undef en_sh
#undef expr_p
#endif