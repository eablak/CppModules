#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

    public: 
    Contact();
    /*
    Kurucu fonksiyonlar üyesi oldukları sınıftan bir nesne yaratılırken kendiliğinden canlanırlar.
    Bu tür fonksiyonlar bir nesnenin kurulması aşamasında yapılması gereken işleri,
    örneğin verilere uygun başlangıç değerleri atamak için kullanılırlar.
    Kurucu fonksiyonlar üyesi oldukları sınıf ile aynı ismi taşırlar.
    Kurucular parametre alırlar, ancak geri dönüş değerleri yoktur
    */
    ~Contact();
    /*
    Bu fonksiyonlar üyesi oldukları sınıftan yaratılmış olan bir nesne bellekten kaldırılırken kendiliğinden çalışırlar.
    Bir nesnenin bellekten kaldırılması için ya nesnenin yaşam alanı sona ermelidir
    (tanımlandığı blok sona ermiştir) ya da dinamik bellekte tanımlanmış olan bir
    nesne delete operatörü ile bellekten silinmelidir.
    Yok edici fonksiyonlar da kurucular gibi sınıf ile aynı ismi taşırlar, ancak
    isimlerinin önünde 'tilda' simgesi (~) yer alır. Yok ediciler parametre almazlar
    ve geriye değer döndürmezler. Bir sınıfta sadece bir adet yok edici fonksiyon olabilir.
    */
    std::string get_firstname();
    std::string get_lastname();
    std::string get_nickname();
    std::string get_phonenumber();
    std::string get_secret();
	void print_contact();
    void set_firstname(std::string first_name);
    void set_lastname(std::string last_name);
    void set_nickname(std::string nick_name);
    void set_phonenumber(std::string phone_number);
    void set_secret(std::string darkest_secret);
};

#endif