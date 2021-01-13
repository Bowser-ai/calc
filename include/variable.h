#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>

class Variable
{
    public:
        Variable(const std::string& name, double value, bool is_const): name{name}, value{value}, is_const{is_const}{}
        bool get_is_const() const noexcept {return is_const;}
        double get_value() const noexcept {return value;}
        void set_value(double value) noexcept {this->value = value;}

    private:
        std::string name;
        double value;
        bool is_const{false};

};

#endif
