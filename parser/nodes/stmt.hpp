#ifndef STMT_HPP
#define STMT_HPP

// visitor list
template<typename C>
class StmtVisitor {
public:
    // virtual C visit();
};


// stmt list
template<typename C>
class Stmt {
public:
    virtual void accept(StmtVisitor<C> visitor);
};


// nodes

#endif