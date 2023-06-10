#include "Base.hpp"

Base * generate(void){
    
    Base *base;
    switch (rand()%3)
    {
        case 0:
        {
            base = new A;
            break;
        }
        case 1:
        {
            base = new B;
            break;
        }
        case 2:
        {
            base = new C;
            break;
        }
    }
    return base;
}

void identify(Base* p){
    if (dynamic_cast<A *>(p))
        std::cout << "A is the identified type by pointer" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B is the identified type by pointer" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C is the identified type by pointer" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
   int i = 0;
   
}