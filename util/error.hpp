#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>


// we'll have errors extend this in this file
class Error {
public:
    std::string error;
    Error(std::string error);
};

#endif