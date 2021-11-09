#include <iostream>
#include <string>
using namespace std;

class ratarata
{
public:
	void hitung(){
	int n;
	int nilai[10];
	int jumlah = 0;
	cout<<"Masukan Banyak Nilai = ";
	cin>>n;
	
	for (int i=0; i<n; i++) 
	{
		cout<<endl;
		
		cout<<"Nilai ke-"<<i+1<<endl;
		cout<<"Masukan Nilai = ";
		cin>>nilai[i];
		jumlah += nilai[i];
	}


	float rata = float(jumlah) / n;
	cout<<"Nilai rata rata : "<<rata<<endl;
	if (rata<=75) {
		cout<<"Status : TIDAK LULUS";
	} else {
		cout<<"Status : LULUS";
	}
	}
	
};

int main()
{
	
ratarata obj;
obj.hitung();
return 0;

}