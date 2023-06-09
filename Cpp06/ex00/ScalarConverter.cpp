#include "ScalarConverter.hpp"

void ScalarConverter::findType(const char *str)
{
    char *ptr;
    long ret;
    int flag = 0;

    ret = strtol(str,&ptr,10);
    if (*ptr == '\0')
    {
        std::cout << "the number " << ret << std::endl;
        this->type = "int";
        flag = 1;
        return ;
    }
    char *neww;
    double ret_d;
    ret_d = strtod(str,&neww);
    if (*neww == '\0')
    {
        std::cout << "the double " << ret_d << std::endl;
        this->type = "double";
        flag = 1;
        return ;
    }
    char *newf;
    float ret_f;
    ret_f = strtof(str,&newf);
    if (*newf == 'f' && *(newf+1) == '\0')
    {
        std::cout << "the float " << ret_f << std::endl;
        this->type = "float";
        flag = 1;
        return ;
    }

    if (flag == 0)
    {
        std::cout << "geçersiz" << std::endl;
        exit(1);
    }
}

std::string &ScalarConverter::getType()
{
    return this->type;
}

ScalarConverter::ScalarConverter(){ return ; }