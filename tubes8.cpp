#include <iostream>
#include <istream>
#include <fstream>
#include <sstream> 
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <cstdio>
#include <iterator>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class Helper {
	public:
	
	template<class X>
	X LowerCase(X str) {
		for(int i=0;str[i]!='\0';i++) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
	    }
	    return str;
	}
};

class Kriptografi {
public:   
   string enkripsi(string str) {
      for(int i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 2;

      return str;
   }

   string dekripsi(string str) {
      for(int i = 0; (i < 100 && str[i] != '\0'); i++)
         str[i] = str[i] - 2;
      
      return str;
   }
};

class Lainnya {
	
	public:
	string convertInt(int number);
	void Header();
	void ulang(string username, string saldo, int nomor_vektor);
};

class Login_Register : private Kriptografi {
	public:
	map<string, string> akun;
	map<string, string> adm;
	map<string, string> saldo_kosong;
	vector<pair <string, string> > account;
	vector<string> vektor_saldo;
	char c;
	Login_Register();
	void login();
	void registrasi();
	void admin();
	void laman_admin();
	void lihat();
	void cari();
	void hapus();
	void tambah();
	void ubahVector(string saldo, int nomor_vektor);
	void ubahFile(string nama_file);
};

class Acak {
	public:
	
	Acak();
	int total;
	int dadu1, dadu2;
	string hasil;
};

class Choice : public Acak{
	public:
	Choice(string username, string saldo, int nomor_vektor);
};

class Menu {
	public:
	Menu();
};

string Lainnya::convertInt(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

void Lainnya::Header() {
	cout << "-------------------------------------------" << endl;
	cout << "            Permainan Tebak Dadu" << endl;
	cout << "-------------------------------------------" << endl;
}

void Lainnya::ulang(string username, string saldo, int nomor_vektor) {
	string lagi;
	
	cout << "Apakah Anda Ingin Mengulang? [YA / TIDAK]" << endl;
	cout << "Jawab : ";
	cin >> lagi;
	Helper hlp;
	
	lagi = hlp.LowerCase(lagi);
	
	try{
		if (lagi == "ya") {
			Choice choice(username, saldo, nomor_vektor);
		}
		else if(lagi == "tidak") {
			cout << "Sampai jumpa!"<<endl;
			exit(0);
		}
		else {
			throw("Silahakan pilih ya atau tidak!");
		}
	}
	catch(const char *msg){
		cerr << "Error : " << msg << endl;
		sleep(1);
		ulang(username, saldo, nomor_vektor);
	}
}

Login_Register::Login_Register() {
	string username, password, saldo;
	int baris = 1;
	ifstream read("akun.txt");
	if(read.is_open()) {
		while(!read.eof()) {
			if(baris % 3 == 1 ) {
				getline(read, username);
			}
			if(baris % 3 == 2) {
				getline(read, password);
				akun.insert(pair<string, string>(username, password));
				account.push_back(make_pair(username, password));
			}
			if(baris % 3 == 0){
				getline(read, saldo);
				vektor_saldo.push_back(saldo);
			}
			baris++;
		}
		read.close();
	}
}

void Login_Register::login(){
	string username, password, saldo;
	Lainnya l;
	
	system("cls");	
	l.Header();
	cout << endl << "   Username : "; cin >> username;
	cout << "   Password : ";
		
	while(c != '\r')
	{
		c = getch();
		if(c == '0') {
			switch(getch()) {
				default:
					break;            
			};
		}
		else if(c == '\b') {
			if(password.size() != 0){
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			password += c;
			cout << "*";
		}
		else
			continue;
	} 

	map<string, string>::iterator iter = akun.find(username);
	
	try {
		if(iter != akun.end()) {
			for (int nomor_vektor = 0; nomor_vektor < account.size(); nomor_vektor++) {
				if(username == account[nomor_vektor].first && password.compare(dekripsi(account[nomor_vektor].second)) == 0){
					saldo = vektor_saldo[nomor_vektor];
					cout << "\n   Login Berhasil" << endl;
					sleep(2);
					system("cls");
					Choice choice(username, saldo, nomor_vektor);
				}
			}
		}
		else {
			throw "Username atau password salah!";
		}
	}
	catch(const char* msg) {
		cerr << "\n   Error : " << msg << endl << endl;
		sleep(1);
		system("cls");
		Menu();
	}
}

void Login_Register::registrasi() {
	string username, password, s;
	Lainnya l;
		
	system("cls");
		
	l.Header();
	cout << "   Username : "; cin >> username;
	cout << "   Password : ";

	while(c != '\r') //Loop until 'Enter' is pressed
	{
		c = getch();
		if(c == '0') {
			switch(getch()) {
				default:
					break;            
			};
		}
		else if(c == '\b') {   //If the 'Backspace' key is pressed
			if(password.size() != 0){  //If the password string contains data, erase last character
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			password += c;
			cout << "*";
		}
		else
			continue;
	} 
	password = enkripsi(password);
	map<string, string>::iterator iter = akun.find(username);
	
	if(iter == akun.end()) {
		akun.insert(pair<string, string>(username, password));
		account.push_back(make_pair(username, password));
		vektor_saldo.push_back("500");
		cout << "\n   Registrasi Berhasil!" << endl;
	}
	else {
		cout << "\n   Akun telah terdaftar! Masukkan username yang berbeda!" << endl;
	}
	
	ubahFile("akun.txt");
	sleep(1);
	system("cls");
	Menu();
}

void Login_Register::admin(){
	string admin, password;
	Lainnya l;
	
	l.Header();
	
	cout << "=============== Login Admin ==============="<<endl; 
	cout << "-------------------------------------------" << endl;
	cout << "  Admin : "; cin >> admin;
	cout << "  Password :";
	while(c != '\r')
	{
		c = getch();
		if(c == '0') {
			switch(getch()) {
				default:
					break;            
			};
		}
		else if(c == '\b') {
			if(password.size() != 0){
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			password += c;
			cout << "*";
		}
		else
			continue;
	} 

	adm.insert(pair<string, string>("admin", "vwdgu"));
	map<string, string>::iterator iter = adm.find(admin);
	
	try{
		if(iter != adm.end() && dekripsi(adm[admin]).compare(password) == 0){
			cout << "\n  Login berhasil, selamat datang " << admin << endl;
			sleep(1);
			system("cls");
			laman_admin();
		}
		else{
			throw "\n  Error : Login Gagal";
		}
	}

	catch(const char* msg){
		cerr << msg << endl;
		sleep(1);
		system("cls");
		Menu menu;
	}
}

void Login_Register::laman_admin(){
	string pilih_pilih;
	Helper hlp;
	Lainnya l;
	
	system("cls");
	l.Header();
	cout << "              Selamat Datang!" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "|           Pilihan menu :                |" << endl;
	cout << "|           1. Lihat Data User            |" << endl;
	cout << "|           2. Cari Data User             |" << endl;
	cout << "|           3. Hapus                      |" << endl;
	cout << "|           4. Tambah Saldo User          |" << endl;
	cout << "|           5. Exit                       |" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Masukkan pilihan Anda : ";
	cin >> pilih_pilih;
	pilih_pilih = hlp.LowerCase(pilih_pilih);
	
	try{
		if (pilih_pilih == "1" || pilih_pilih == "lihat"){
			lihat();
		}
		else if (pilih_pilih == "2" || pilih_pilih == "cari"){
			cari();
		}
		else if (pilih_pilih == "3" || pilih_pilih == "hapus"){
			hapus();
		}
		else if (pilih_pilih == "4" || pilih_pilih == "tambah") {
			tambah();
		}
		else if (pilih_pilih == "5" || pilih_pilih == "exit"){
			cout<<"Goodbye Admin Tebak Dadu"<<endl;
			sleep(1);
			system("cls");
			Menu menu;
			exit(0);
		}
		else{
			throw "Silahkan Pilih 1 , 2 , 3 atau 4!";
		}
	}

	catch (const char *msg){
		cerr << "Error : " << msg << endl << endl;
		sleep(1);
		system("cls");
		laman_admin();
	}
}

void Login_Register::lihat() {
	int nomor = 2;
	string kembali;
	Lainnya l;
	map<string, string>::iterator it_admin = adm.find("admin");
	
	system("cls");
	l.Header();
	cout << "|                Data User                |" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "|No.  Username     Password     Saldo     |" << endl;
	cout << "|" << setiosflags(ios::left) << setw(5) << "1"
		 << setiosflags(ios::left) << setw(13) << it_admin->first
		 << setiosflags(ios::left) << setw(13) << dekripsi(it_admin->second)
		 << setiosflags(ios::left) << setw(10) << "-" << "|" << endl; 
		 
	for (int nomor_vektor = 0; nomor_vektor < account.size(); nomor_vektor++) {
		cout << "|" << setiosflags(ios::left) << setw(5) << nomor
			 << setiosflags(ios::left) << setw(13) << account[nomor_vektor].first
			 << setiosflags(ios::left) << setw(13) << dekripsi(account[nomor_vektor].second)
			 << setiosflags(ios::left) << setw(10) << vektor_saldo[nomor_vektor] << "|" << endl;
		nomor++;
	}
	
	cout << "|-----------------------------------------|" << endl;
	cout << "Tekan 1 jika ingin kembali ke Menu Utama" << endl ;
	cin >> kembali;
	
	try {
		if(kembali == "1") {
			laman_admin();
		}
		else {
			throw "\nKode salah!";
		}
	}
	catch(const char* msg) {
		cerr << msg << endl;
		sleep(1);
		lihat();
	}
}

void Login_Register::cari(){
	string username, kembali = "x";
	Lainnya l;
	
	system("cls");
	l.Header();
	cout << "============= Cari Data User ==============" << endl; 
	cout << "-------------------------------------------" << endl;
	cout << "Username : "; cin >> username;
	
	map<string, string>::iterator iter = akun.find(username);
	try {
		if(iter != akun.end()) {
			for (int nomor_vektor = 0; nomor_vektor < account.size(); nomor_vektor++) {
				if(username == account[nomor_vektor].first){
					cout << "-------------------------------------------" << endl;
					cout << "=============== Info Player ==============="<<endl;
					cout << "Username : " << username << endl;
					cout << "Password : " << dekripsi(akun[username]) << endl;
					cout << "Saldo    : " << vektor_saldo[nomor_vektor] << endl;
				}
			}
		}
		else {
			throw "Akun tidak ditemukan";
		}
	}
	catch(const char* msg) {
		cerr << "\nError : " << msg << endl << endl;
		sleep(1);
		system("cls");
		laman_admin();
	}
		
	while (kembali != "1") {
		cout << "Tekan 1 jika ingin kembali ke Menu Utama" << endl ;
		cin >> kembali;
	}
	
	if(kembali == "1") {
		laman_admin();
	}
}

void Login_Register::hapus(){
		string u, yakin = "x";
		int saldo;
		Lainnya l;
		Helper hlp;
		
		system("cls");
		l.Header();
		cout << "================ Hapus Akun ================"<<endl; 
		cout << "-------------------------------------------" << endl;
		cout << "Masukkan username: ";
        cin >> u;
		
		map<string, string>::iterator it = akun.find(u);
		try{
			if (it == akun.end()){
				throw "\nAkun tidak ditemukan!\n";
			}
			else {
				for(int nomor_vektor = 0; nomor_vektor < account.size(); nomor_vektor) {
					if(account[nomor_vektor].first == u) {
						while (yakin != "ya" && yakin != "tidak") {
							cout << "Apakah Anda yakin ingin menghapus akun ini? [YA / TIDAK]" << endl;
							cin >> yakin;
							yakin = hlp.LowerCase(yakin);
						}
						
						if(yakin == "ya") {
							akun.erase(u);
							account.erase(account.begin() + nomor_vektor);
							vektor_saldo.erase(vektor_saldo.begin() + nomor_vektor);
							ubahFile("akun.txt");
							cout <<	"Akun Berhasil dihapus" << endl;
							sleep(2);
							system("cls");
							laman_admin();
							break;
						}
						else {
							system("cls");
							laman_admin();
						}
					}
					nomor_vektor++;
				}
			}
		}
		catch (const char *msg){
			cerr << "Error : " << msg << endl << endl;
			sleep(1);
			system("cls");
			laman_admin();
		}
}

void Login_Register::tambah() {
	int nomor = 1;
	string username;
	Lainnya l;
	
	system("cls");
	
	cout << "============== Tambah Saldo ===============" << endl; 
	cout << "-------------------------------------------" << endl;
	cout << "	   Penambahan saldo hanya 500         " << endl;
	cout << "-------------------------------------------" << endl;
	cout << "| Berikut data user yang memiliki saldo 0 |" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "|                Data User                |" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "|No.  Username     Password     Saldo     |" << endl;
	
	for (int nomor_vektor = 0; nomor_vektor < account.size(); nomor_vektor++) {
		if(vektor_saldo[nomor_vektor] == "0") {
			string password_baru = dekripsi(account[nomor_vektor].second);
			cout << "|" << setiosflags(ios::left) << setw(5) << nomor
				 << setiosflags(ios::left) << setw(13) << account[nomor_vektor].first
				 << setiosflags(ios::left) << setw(13) << password_baru
				 << setiosflags(ios::left) << setw(10) << vektor_saldo[nomor_vektor] << "|" << endl;
			saldo_kosong.insert(pair<string, string>(account[nomor_vektor].first, password_baru));
			 
		}
		nomor++;
	}
	cout << "|-----------------------------------------|" << endl << endl;
	cout << "Masukkan username yang ingin saldo ditambah: ";
	cin >> username;
	
	map<string, string>::iterator it = saldo_kosong.find(username);
	try {
		if(it != saldo_kosong.end()) {
			for (int vek = 0; vek < saldo_kosong.size(); vek++) {
				if(username == account[vek].first){
					vektor_saldo[vek] = "500";
					ubahFile("akun.txt");
					break;
				}
			}
			cout << "Saldo berhasil ditambah!" << endl;
			sleep(2);
			system("cls");
			laman_admin();
		}
		else {
			throw "Akun tidak ditemukan";
		}
	}
	catch(const char* msg) {
		cerr << "\nError : " << msg << endl << endl;
		sleep(1);
		system("cls");
		laman_admin();
	}
	
}

void Login_Register::ubahVector(string saldo, int letak_saldo) {
	vektor_saldo[letak_saldo] = saldo;
}

void Login_Register::ubahFile(string nama_file){
	ofstream read;
	read.open(nama_file.c_str(), ios::trunc);
	for(int nomor_vektor = 0; nomor_vektor < account.size(); nomor_vektor){
		read << account[nomor_vektor].first << endl 
			 << account[nomor_vektor].second << endl 
			 << vektor_saldo[nomor_vektor] << endl;
		nomor_vektor++;
	}
	read.close();
}

Acak::Acak() {
	string hasil;
	srand(time(0));
		
	dadu1 = 1 + (rand() % 6);
	dadu2 = 1 + (rand() % 6);
		
	total = dadu1 + dadu2;
		
	if (total % 2 == 1){
		hasil = "ganjil";
		this->hasil = hasil;
	}
	else {
		hasil = "genap";
		this->hasil = hasil;
	}
}

Choice::Choice(string username, string saldo, int nomor_vektor){
	string pilihan, choice, tebak, ngulang;
	Lainnya l;
	Login_Register lr;
	
	system("cls");
	
	if(saldo == "0") {
		l.Header();
		cout << "Saldo Anda telah habis! Silahkan masuk ke halaman admin123!" << endl;
		sleep(4);
		system("cls");
		Menu menu();
	}
	else {
		l.Header();
		cout << "        Tebak dadu ganjil genap" << endl;
		cout << "-------------------------------------------" << endl << endl;
		cout << "Selamat datang " << username << "!\nSaldo Anda = " << saldo << endl;
		cout << "Masukkan tebakan Anda (ganjil / genap) : ";
		cin >> pilihan;
		
			system("cls");
			cout << "Loading System";
    		sleep(1);
    		cout << ".....";
		    sleep(1);
		    cout << ".......";
		    sleep(1);
		    cout << ".........";
		    system("cls");

		    cout<<endl<<endl;
			
		Helper lower;
		choice = lower.LowerCase(pilihan);
		
		try {
			if(choice != "ganjil" && choice != "genap"){
				throw "Masukkan pilihan yang benar";
			}
		}
		catch(const char *msg){
			cerr<<"Error : "<<msg<<endl;
			sleep(3);
			Choice choice(username, saldo, nomor_vektor);
		}
		
		int sal;
		int saldointakhir;
		string strtoint;
		string ubah = saldo;
		sal = atoi(ubah.c_str());

		if (dadu1 == 1 && dadu2 == 1)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*       *" << "  " << "*       *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "*       *" << "  " << "*       *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 1 && dadu2 == 2)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*       *" << "  " << "* *     *" << endl;
			cout << "*   *   *" << "  " << "*       *" << endl;
			cout << "*       *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 1 && dadu2 == 3)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*       *" << "  " << "* *     *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "*       *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 1 && dadu2 == 4)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*       *" << "  " << "* *   * *" << endl;
			cout << "*   *   *" << "  " << "*       *" << endl;
			cout << "*       *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 1 && dadu2 == 5)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*       *" << "  " << "* *   * *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "*       *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 1 && dadu2 == 6)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*       *" << "  " << "*  * *  *" << endl;
			cout << "*   *   *" << "  " << "*  * *  *" << endl;
			cout << "*       *" << "  " << "*  * *  *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}


		else if (dadu1 == 2 && dadu2 == 1)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "*       *" << endl;
			cout << "*       *" << "  " << "*   *   *" << endl;
			cout << "*     * *" << "  " << "*       *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 2 && dadu2 == 2)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *     *" << endl;
			cout << "*       *" << "  " << "*       *" << endl;
			cout << "*     * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 2 && dadu2 == 3)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *     *" << endl;
			cout << "*       *" << "  " << "*   *   *" << endl;
			cout << "*     * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 2 && dadu2 == 4)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *   * *" << endl;
			cout << "*       *" << "  " << "*       *" << endl;
			cout << "*     * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 2 && dadu2 == 5)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *   * *" << endl;
			cout << "*       *" << "  " << "*   *   *" << endl;
			cout << "*     * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 2 && dadu2 == 6)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "*  * *  *" << endl;
			cout << "*       *" << "  " << "*  * *  *" << endl;
			cout << "*     * *" << "  " << "*  * *  *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}


		else if (dadu1 == 3 && dadu2 == 1)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "*       *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "*     * *" << "  " << "*       *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 3 && dadu2 == 2)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *     *" << endl;
			cout << "*   *   *" << "  " << "*       *" << endl;
			cout << "*     * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 3 && dadu2 == 3)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *     *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "*     * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 3 && dadu2 == 4)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *   * *" << endl;
			cout << "*   *   *" << "  " << "*       *" << endl;
			cout << "*     * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 3 && dadu2 == 5)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "* *   * *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "*     * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 3 && dadu2 == 6)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *     *" << "  " << "*  * *  *" << endl;
			cout << "*   *   *" << "  " << "*  * *  *" << endl;
			cout << "*     * *" << "  " << "*  * *  *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}


		else if (dadu1 == 4 && dadu2 == 1)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "*       *" << endl;
			cout << "*       *" << "  " << "*   *   *" << endl;
			cout << "* *   * *" << "  " << "*       *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 4 && dadu2 == 2)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *     *" << endl;
			cout << "*       *" << "  " << "*       *" << endl;
			cout << "* *   * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 4 && dadu2 == 3)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *     *" << endl;
			cout << "*       *" << "  " << "*   *   *" << endl;
			cout << "* *   * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 4 && dadu2 == 4)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*       *" << "  " << "*       *" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 4 && dadu2 == 5)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*       *" << "  " << "*   *   *" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 4 && dadu2 == 6)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "*  * *  *" << endl;
			cout << "*       *" << "  " << "*  * *  *" << endl;
			cout << "* *   * *" << "  " << "*  * *  *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}


		else if (dadu1 == 5 && dadu2 == 1)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "*       *" << endl;
			cout << "*  *    *" << "  " << "*   *   *" << endl;
			cout << "* *   * *" << "  " << "*       *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 5 && dadu2 == 2)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *     *" << endl;
			cout << "*   *   *" << "  " << "*       *" << endl;
			cout << "* *   * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 5 && dadu2 == 3)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *     *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "* *   * *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 5 && dadu2 == 4)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*   *   *" << "  " << "*       *" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 5 && dadu2 == 5)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*   *   *" << "  " << "*   *   *" << endl;
			cout << "* *   * *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 5 && dadu2 == 6)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "* *   * *" << "  " << "*  * *  *" << endl;
			cout << "*   *   *" << "  " << "*  * *  *" << endl;
			cout << "* *   * *" << "  " << "*  * *  *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}

		else if (dadu1 == 6 && dadu2 == 1)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*  * *  *" << "  " << "*       *" << endl;
			cout << "*  * *  *" << "  " << "*   *   *" << endl;
			cout << "*  * *  *" << "  " << "*       *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 6 && dadu2 == 2)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*  * *  *" << "  " << "* *     *" << endl;
			cout << "*  * *  *" << "  " << "*       *" << endl;
			cout << "*  * *  *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 6 && dadu2 == 3)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*  * *  *" << "  " << "* *     *" << endl;
			cout << "*  * *  *" << "  " << "*   *   *" << endl;
			cout << "*  * *  *" << "  " << "*     * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 6 && dadu2 == 4)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*  * *  *" << "  " << "* *   * *" << endl;
			cout << "*  * *  *" << "  " << "*       *" << endl;
			cout << "*  * *  *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 6 && dadu2 == 5)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*  * *  *" << "  " << "* *   * *" << endl;
			cout << "*  * *  *" << "  " << "*   *   *" << endl;
			cout << "*  * *  *" << "  " << "* *   * *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}else if (dadu1 == 6 && dadu2 == 6)
		{
			cout << "*********" << "  " << "*********" << endl;
			cout << "*  * *  *" << "  " << "*  * *  *" << endl;
			cout << "*  * *  *" << "  " << "*  * *  *" << endl;
			cout << "*  * *  *" << "  " << "*  * *  *" << endl;
			cout << "*********" << "  " << "*********" << endl;
		}
			
		if (choice == hasil) {
    		cout << "Loading System";
    		sleep(1);
    		cout << ".....";
		    sleep(1);
		    cout << ".......";
		    sleep(1);
		    cout << ".........";
			cout <<endl<< "Selamat Tebakan Benar" <<endl<<endl;
			cout << "Dadu 1 = " << dadu1 << endl;
			cout << "Dadu 2 = " << dadu2 << endl;
			cout << "Total dadu = " << total << endl;
			cout << "Pilihan anda = " << choice << endl;
			cout << "Pilihan yang tepat = " << hasil << endl << endl;
				
			saldointakhir = sal + 100;
			strtoint= l.convertInt(saldointakhir);
			
			lr.ubahVector(strtoint, nomor_vektor);
			lr.ubahFile("akun.txt");
			
			cout << "Saldo Anda saat ini = " << strtoint << endl<<endl;
			l.ulang(username, strtoint, nomor_vektor);
		}
		else {
		    cout << "Loading System";
		    sleep(1);
		    cout << ".....";
		    sleep(1);
		    cout << ".......";
		    sleep(1);
		    cout << ".........";
			cout <<endl<< "Maaf Tebakan Salah"<<endl<< endl;
			cout << "Dadu 1 = " << dadu1 << endl;
			cout << "Dadu 2 = " << dadu2 << endl;
			cout << "Total dadu = " << total << endl;
			cout << "Pilihan anda = "<<choice<<endl;
			cout << "Pilihan yang tepat = "<<hasil<<endl<<endl;
				
			saldointakhir = sal - 25;
			strtoint= l.convertInt(saldointakhir);
			
			lr.ubahVector(strtoint, nomor_vektor);
			lr.ubahFile("akun.txt");
			
			cout << "Saldo Anda saat ini = " << strtoint << endl<<endl;
			l.ulang(username, strtoint, nomor_vektor);
		}
	}
}

Menu::Menu() {
	string pilih_pilih;
	Lainnya l;
	Helper hlp;
	Login_Register lr;
		
	l.Header();
	cout << "              Selamat Datang!" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "|           Pilihan menu :                |" << endl;
	cout << "|           1. Login                      |" << endl;
	cout << "|           2. Register                   |" << endl;
	cout << "|           3. Exit                       |" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Masukkan pilihan Anda : ";
	cin >> pilih_pilih;
	pilih_pilih = hlp.LowerCase(pilih_pilih);
	
	try{
		if (pilih_pilih == "1" || pilih_pilih == "login"){
			system("CLS");
    		cout << "Loading System";
    		sleep(1);
    		cout << ".....";
    		sleep(1);
    		cout << ".......";
    		sleep(1);
    		cout << ".........";
			Login_Register lr;
			lr.login();
		}
		else if (pilih_pilih == "2" || pilih_pilih == "register"){
			system("CLS");
		    cout << "Loading System";
		    sleep(1);
		    cout << ".....";
		    sleep(1);
		    cout << ".......";
		    sleep(1);
		    cout << ".........";
			Login_Register lr;
			lr.registrasi();
		}
		else if (pilih_pilih == "3" || pilih_pilih == "exit"){
			cout << "Silahkan bermain lagi nanti!" << endl;
			sleep(2);
			system("cls");
			exit(0);
		}
		else if (pilih_pilih == "admin123"){
			system("CLS");
    		cout << "Loading System";
    		sleep(1);
    		cout << ".....";
		    sleep(1);
		    cout << ".......";
		    sleep(1);
		    cout << ".........";
			lr.admin();
		}
		else{
			throw "Silahkan Pilihlah dengan benar yaitu 1, 2, 3 !";
		}
	}

	catch (const char *msg){
		cerr << "Error : " << msg << endl << endl;
		sleep(1);
		system("cls");
		Menu();
	}
}

int main () {
	
	Menu menu;
	
	return 0;
}