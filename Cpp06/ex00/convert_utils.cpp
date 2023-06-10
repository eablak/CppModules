#include "ScalarConverter.hpp"

long int convert_int(ScalarConverter *s)
{
    char *ptr;
    long ret;
    std::string str = s->getString();
    ret = strtol(&str[0],&ptr,10);
    return ret;
}

float convert_float(ScalarConverter *s)
{
    char *ptr;
    float ret_f;
    std::string str = s->getString();
    ret_f = strtof(&str[0],&ptr);
    return ret_f;
}

double convert_double(ScalarConverter *s)
{
    char *ptr;
    double ret_d;
    std::string str = s->getString();
    ret_d = strtod(&str[0],&ptr);
    return ret_d;
}
