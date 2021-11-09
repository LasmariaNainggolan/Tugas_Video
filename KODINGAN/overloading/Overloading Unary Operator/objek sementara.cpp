#include <iostream>

using namespace std;

class Hitung {
    private:
       int angka;
    
    public:
       Hitung() : angka(0) {}
       
       int getAngka() { return angka; }
       
       Hitung operator ++ () {
           ++angka;
           Hitung temp;
           temp.angka = angka;
           return temp;
       }
     
};

int main() {
    
        Hitung c1, c2;
        
        cout << "Sebelum increment: " << endl;
        cout << "c1 = " << c1.getAngka() << endl;
        cout << "c2 = " << c2.getAngka() << endl;
        
        ++c1;
        ++c1;
        c2 = ++c1;
        
        cout << "setelah inceremnt: " << endl;
        cout << "c1 = " << c1.getAngka() << endl;
        cout << "c2 = " << c2.getAngka() << endl;
        
    return 0;
}