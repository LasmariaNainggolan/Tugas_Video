#include <iostream>
#include <string>
using namespace std;

class kecepatan
{
public:
	void hitung(){
		int n;
		string nama[10],status[10];
		float jarak[10];
		float waktu[10];
		float kecepatan[10];


		cout<<"Masukan Jumlah Kendaraan = ";
		cin>>n;

		for (int i=0; i<n; i++) {
			cout<<endl;

			cout<<"Data ke-"<<i+1<<endl;
			cout<<"Masukan Nama Kendaraan = ";
			cin>>nama[i];
			cout<<"Masukan jarak tempuh (dalam km) = ";
			cin>>jarak[i];
			cout<<"Masukan waktu tempuh (dalam jam) = ";
			cin>>waktu[i];

			kecepatan[i] = jarak[i] / waktu[i];

			if (kecepatan[i]<=60) {
				status[i]="Kecepatan Rendah";
			} else {
				status[i]="Kecepatan Tinggi";
			}
		}
		cout<<endl;
		cout<<"DAFTAR jarak MAHASISWA"<<endl;
		cout<<"---------------------------------------------------------------------------------------------------"<<endl;
		cout<<"No    Nama           Jarak(km)           Waktu(jam)           kecepatan(km/jam)           Status         "<<endl;
		cout<<"---------------------------------------------------------------------------------------------------"<<endl;

		for (int i=0; i<n;i++) {
			cout<<i+1<<"     "<<nama[i]<<"             "<<jarak[i]<<"                 "<<waktu[i]<<"                         "<<kecepatan[i]<<"             "<<status[i]<<endl;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;
		}

	}
	
};

int main()
{
	kecepatan obj;
	obj.hitung();
	return 0;
}
