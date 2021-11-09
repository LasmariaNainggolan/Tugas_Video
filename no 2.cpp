#include <iostream> 

using namespace std; 

class balikBilangan 
{ 
	private: 
	    int a, b, t;

	public: 
	
		int swap(int x, int y)
        {
            a = x;
            b = y;
            
            t = a;
            a = b;
            b = t;

        };
        
		int output() 
		{ 
			cout<<"\nSetelah dibalik:" << endl;
			cout<<"a = " <<a << endl; 
			cout<<"b = " <<b << endl; 
		} 
}; 

int main() 
{ 
	balikBilangan obj; 
	obj.swap(20, 40);
	    cout<<"Program Membalik Bilangan Bulat (a = 20 dan b = 40)" <<endl;
	obj.output(); 
	return 0; 
};
