#ifndef VAL_HPP
#define VAL_HPP

#include <string>


class Val {
public:
    typedef enum Type {
        String,
        Number,
        Bool,
        Null
    } Type;

    Type type;

    std::string string;
    double number;
    bool boolean;

    Val(std::string val);
    Val(double val);
    Val(bool val);
    Val();
};

#endif