#include <iostream>
int	main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    std::cout << "Address of string " << &string << std::endl;
    std::cout << "Address of stringPTR " << stringPTR << std::endl;
    std::cout << "Address of stringREF " << &stringREF << std::endl;
    std::cout << "Value of string " << string << std::endl;
    std::cout << "Value of stringPTR " << *stringPTR << std::endl;
    std::cout << "Value of stringREF " << stringREF << std::endl;
}

/*
!!! Referanslar kendisi const olan bir pointerın seviyesi yükseltilmiş halidir. 
        scope boyunca referans gösterdiği nesneyi temsil eder, başka bir nesneyi gösteremez. 
            Yani referanslara ilk değer vermek zorunlu derken arka plan da const oldukları içindir. !!!

-> Bir pointer kendisi const olmak zorunda değil, hayatı devam ettiği sürece farklı nesneleri gösterebilir.
-> Referansta böyle değil kendi const, referans hep aynı nesnenin yerine geçer.
-> Elemanların referans olan bir dizi diye birşey yok ama bir referans bir dizinin yerine geçebilir.
-> Pointer dizileri var.
*/

