#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <stdlib.h>
#include <cstring>

class ScalarConverter{
    int type;
    std::string str;

    public:
    enum types { _char, _int, _float, _double, _unknown};
    void setType(int enum_nbr);
    void findType(ScalarConverter *s);
    int getType();
    void setString(std::string str);
    const std::string &getString() const;

    // ScalarConverter(std::string str);

    ScalarConverter();
    // ScalarConverter(const ScalarConverter &copyS);
    // ScalarConverter &operator=(const ScalarConverter &copyS);
    // ~ScalarConverter();
};

#endif