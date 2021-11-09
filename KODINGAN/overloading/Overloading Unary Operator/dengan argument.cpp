#include<iostream>

using namespace std;

class UnaryFriend {
private:
   int a = 10, b = 20, c = 30;
   
public:
   void show() {
        cout << a << "\n" << b << "\n" << c << "\n" << endl;
   }
   
   void friend operator-(UnaryFriend &x);
};

   void operator-(UnaryFriend &x) {
       x.a = -x.a;
       x.b = -x.b;
       x.c = -x.c;
   }
   
   int main () {
       
       UnaryFriend x1;
       
       cout<< "Sebelum Overloading" << endl;
       x1.show();
       
       cout << "Setelah Overloading" << endl;
       -x1;
       x1.show();
       
       return 0;
   }
