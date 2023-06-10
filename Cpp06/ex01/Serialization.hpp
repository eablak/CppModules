#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include <iostream>
#include <stdint.h> //linux
// #include <cstdint>

typedef struct Data
{
    std::string login;
    double      level;
} t_data;

class Serialization{

    public:
    
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);

    Serialization();
    Serialization(const Serialization &copyS);
    Serialization &operator=(const Serialization &copyS);
    ~Serialization();
};

#endif
