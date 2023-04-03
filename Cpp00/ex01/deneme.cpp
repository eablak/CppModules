#include <iostream>

using namespace std;

class Kisi {
private:
  string adi;
protected:
  string soyadi;
public:
  static int nesneSayisi;
  Kisi(string a, string s) {
    cout << "Nesne olusturuluyor." << endl;
    this->adi = a;
    (*this).soyadi = s;
    Kisi::nesneSayisi++;
  }
  string yazdir() {
    return this->adi + " " + this->soyadi;
  }
  ~Kisi() {
    cout << "Nesne siliniyor." << endl;
  }
};

int Kisi::nesneSayisi = 0;

int main(){
  Kisi *p;
  Kisi k1("Yusuf", "SEZER");
  Kisi k2("Sinan", "SEZER");

  p = &k2;

  cout << k1.yazdir() << endl;
  cout << p->yazdir() << endl;

  cout << "Kopya sayisi : " << Kisi::nesneSayisi << endl;

  return 0;
}