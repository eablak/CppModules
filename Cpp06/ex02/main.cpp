#include "Base.hpp"

int main(){
    Base *base;
    for(int i = 0; i< 20; i++)
    {
        base = generate();
        identify(base);
        identify(*base);
        usleep(1000000000);
        std::cout << std::endl;
    }
}