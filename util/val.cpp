#include "val.hpp"


Val::Val(std::string val) {
    type = String;
    string = val;
}

Val::Val(double val) {
    type = Number;
    number = val;
}

Val::Val() {
    type = Null;
}