#include <iostream>

using namespace std;

class Hitung {
private:
  int angka;
  
public:
  Hitung() : angka(5) {}
  
  int getAngka() { return angka; }
  
  void operator -- () { --angka;}
};

int main() {
    
    Hitung c1, c2;
    
    cout << "Sebelum decrement: " << endl;
    cout << c1.getAngka() << endl;
    cout << c2.getAngka() << endl;
    
    --c1;
    --c2;
    --c2;
    
    cout << "Setelah decrement: " << endl;
    cout << c1.getAngka() << endl;
    cout << c2.getAngka() << endl;
    
    return 0;
}