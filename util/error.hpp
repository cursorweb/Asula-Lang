#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <string>
#include <sstream>

#include "../lexer/token.hpp"


// we'll have errors extend this in this file
class Error {
protected:
    LineInfo lf;
    std::string error;

public:
    Error(LineInfo lf = LineInfo(), std::string error = "");

    void show_error();
};

#endif