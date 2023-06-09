#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <stdlib.h>

class ScalarConverter{
    std::string type;
    const std::string str;

    public:
    void findType(const char *str);
    std::string &getType();

    // ScalarConverter(std::string str);

    ScalarConverter();
    // ScalarConverter(const ScalarConverter &copyS);
    // ScalarConverter &operator=(const ScalarConverter &copyS);
    // ~ScalarConverter();
};

#endif