#include "ScalarConverter.hpp"

int is_int(ScalarConverter *s)
{
    char *ptr;
    std::string str = s->getString();
    strtol(&str[0],&ptr,10);
    if (*ptr == '\0')
    {
        s->setType(1);
        return 1;
    }
    return (0);
}

int is_float(ScalarConverter *s)
{
    char *ptr;
    std::string str = s->getString();
    strtof(&str[0],&ptr);
    if (*ptr == 'f' && *(ptr+1) == '\0')
    {
        s->setType(2);
        return 1;
    }
    return (0);
}

int is_double(ScalarConverter *s)
{
    char *ptr;
    std::string str = s->getString();
    strtod(&str[0],&ptr);
    if (*ptr == '\0')
    {
        s->setType(3);
        return 1;
    }
    return (0);
}

int is_char(ScalarConverter *s)
{
    std::string str = s->getString();

    if (strlen(&str[0]) == 1)
    {
        s->setType(0);
        return 1;
    }
    return 0;
}

void ScalarConverter::findType(ScalarConverter *s)
{
    
    while(1)
    {
        if (is_int(s))
            break;
        if (is_float(s))
            break;
        if (is_double(s))
            break;
        if (is_char(s))
            break;
        else
        {
            s->setType(4);
            break;
        }
    }
}

void ScalarConverter::setType(int enum_nbr)
{
    this->type = enum_nbr;
}

int ScalarConverter::getType()
{
    return this->type;
}

void ScalarConverter::setString(std::string str)
{
    this->str = str;
}

const std::string &ScalarConverter::getString() const
{
    return this->str;
}

ScalarConverter::ScalarConverter(){ return ; }