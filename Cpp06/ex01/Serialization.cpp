#include "Serialization.hpp"

Serialization::Serialization(){ }
Serialization::Serialization(const Serialization &copyS) { 
    *this = copyS;}
Serialization &Serialization::operator=(const Serialization &copyS) { 
    if (this == &copyS)
        return (*this);
    return (*this); }
Serialization::~Serialization(){}

uintptr_t Serialization::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}