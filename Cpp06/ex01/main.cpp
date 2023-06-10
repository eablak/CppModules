#include "Serialization.hpp"

int main()
{
    t_data data;
    data.login = "xlogin";
    data.level = 10.5;

    t_data *data2 = new Data;
    data2->login = "ylogin";
    data2->level = 8.7;

    Serialization s;
    std::cout << "before serialized: " << std::endl;
    std::cout << "data: " << &data << " data2: " << data2 << std::endl;
    std::cout << "data " << data.login << " data2: " << data2->login << std::endl;
    std::cout << "data " << data.level << " data2: " << data2->level << std::endl;
    data2 = s.deserialize(s.serialize(&data));
    std::cout << "after serialized: " << std::endl;
    std::cout << "data: " << &data << " data2: " << data2 << std::endl;
    std::cout << "data: " << data.login << " data2: " << data2->login << std::endl;
    std::cout << "data: " << data.level << " data2: " << data2->level << std::endl;

    std::cout << std::endl;

    t_data *data3 = new Data;
    data3 = s.deserialize(s.serialize(data2));
    std::cout << "data3: " << data3 << std::endl;
    std::cout << "data3: " << data3->login << std::endl;
    std::cout << "data3: " << data3->level << std::endl;
}