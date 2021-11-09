#include <iostream>
#include <sstream> 

using namespace std;

class Tabungan{
  private:
  // Tidak bisa diakses objek lain
  long long int tabungan;

  public:
  Tabungan(){
    // Inisiasi nilai tabungan
    this->tabungan = 0;
  }

  void tambahSaldo(string nominal){
    long long int angka;
    try{
      // Memeriksa nomial adalah numerik
      for (int i = 0; i < nominal.length(); i++){
        if(!isdigit(nominal[i]))
          throw 0;
      }
      // Konversi string ke int
      stringstream s(nominal);
      s >> angka;
      // Nominal minus
      if(angka < 0){
        throw 1;
      // Nominal lebih dari 10 juta
      } else if(angka > 10000000){
        throw 2;
      }
    } catch(int e){
      cout << "Error : ";
      if(e == 0){
        cout << "Bukan numerik" << endl;
      } else if(e == 1){
        cout << "Nominal minus" << endl;
      } else if(e == 2){
        cout << "Nominal lebih dari 10 juta rupiah" << endl;
      }else {
        cout << "Kesalahan tidak diketahui" << endl;
      }
      return;
    }
    this->tabungan += angka;
  }

  long long int cekSaldo(){
    // Mengembalikan nominal saldo
    return this->tabungan;
  }

  ~Tabungan(){}
};

int main(){
  Tabungan nasabah;
  nasabah.tambahSaldo("1000");
  cout << nasabah.cekSaldo() << endl;
  return 0;
}