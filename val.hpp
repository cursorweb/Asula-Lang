#ifndef VAL_HPP
#define VAL_HPP

#include <string>


class Val {
public:
    typedef enum Type {
        String,
        Number,
        Null
    } Type;

    Type type;

    std::string string;
    float number;

    Val(std::string val);
    Val(float val);
    Val();
};

#endif