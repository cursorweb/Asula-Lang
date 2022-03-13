#ifndef STMT_HPP
#define STMT_HPP




// visitor list
class StmtVisitor;


// stmt list
class Stmt {
public:
    virtual void accept(StmtVisitor visitor);
};


// nodes


// visitor list
class StmtVisitor {
public:
    // virtual C visit();
};

#endif