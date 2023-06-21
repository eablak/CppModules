#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(){
    Base *base;
    for(int i = 0; i< 20; i++)
    {
        base = generate();
        identify(base);
        identify(*base);
        usleep(100000);
        std::cout << std::endl;
    }
}