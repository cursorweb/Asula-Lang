#include "error.hpp"

// base
Error::Error(LineInfo lf, std::string error) {
    this->lf = lf;
    this->error = error;
}

void Error::show_error() {
    // [1:2] error
    std::cout << "[" << lf.line << ":" << lf.col << "] : " << error << std::endl;
}