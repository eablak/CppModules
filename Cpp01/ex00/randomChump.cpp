#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zombie(name); //stack'te açıyosun
    zombie.announce();
}

/*
    Stack - Yığıt
-> Sürekli dolma sonucunda meydana gelen bir veri yapısı.
-> Veriler üst üste biniyor. En üstteki verileri ata ata aşağıdaki verilere erişiyoruz.


| V3 |  * V1'deki veriye ulaşmak için V3 ve V2'nin çıkarılması gerekiyor.
| V2 |  * Recursive fonksiyonların geri dönüş değerlerin nihai sonucuna ulaşılmasında kullanılıyor stack'ler.
| V1 |  * Programın içerisindeki sıralı akışta kullanılıyor (değişkenler).
|____|  * FILO (first in last out)


-> Geçici değişkenlerin depolandığı yer.
-> Bir iş parçacığı yürütmek için kullanılıyor (thread)
-> Yığın içerisinde depolanan değişkenler onları oluşturan işlev çalıştığı sürece var oluyor.
    Örn: Bir metod oluşturdun. O metod içerisinde olduğun sürece scope'da kaldığın sürece o değişkenler yığında olmaya
    devam ediyor. Ne zaman metodla çalışma işin bitti. Metodun içerisinde oluşturduğun local değişkenler ortadan kalkıyor.
-> Boyutları kullanılan işletim sistemine göre değişir.
-> Kullanılan bölgeler iş bitince serbest bırakılıyor.

    Yerel değişkenler neden Stack'te depolanıyor ??
=> Bir fonksiyondan farklı fonksiyonlara, metodlara geçtiğimizde o fonksiyon tamamlandığında içerisinde oluşturulmuş değişkenler
silinsin diye böyle bir mekanizma söz konusu. 


!! Stack'in amacı değişkenlerin değerlerini, objelerinin adreslerini tutmak. Yani aslında sadece bir adres gösterme, bir bilgi
göstermeden ziyade o bilginin var olduğu adresin kaynağı bu stack'lerin içerisinde tutulur.

yigin.add(10);  |30|
yigin.add(20);  |20|
yigin.add(30);  |10|
printl(yıgın.peek()) -> 30
yigin.pop() -> 30'u sildi
printl(yıgın.peek()) -> 20
yigin.pop() -> 20 sildi
printl(yıgın.peek()) -> 10
yigin.pop() -> 10 sildi
printl(yıgın.peek()) -> hata
*/