#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <map>
using namespace std;


//ifstream lihat("admin2.txt", ios::in);
ifstream baca("barang.csv", ios::in);
ofstream masukan("barang.csv", ios::app | ios::trunc);
ifstream datum("admin.csv", ios::in);
ofstream fout("admin.csv", ios::app);
vector <int> harga, stok, row, total, keranjangbeli, keranjangharga, vekharga, vekstok;
vector <string> nama, keranjangnama, veknama;
vector<string> parsedName, parsedPas;
map<string,string>akun;
int a,b,c,d;


class proses : public prosesdata, tuliscsv{
   private:
      int pilih; char w;        
   public:
    void prosesadmin(void){
         system("cls");
            cout<<"\t\t\t\t          =====================================\n";
            cout<<"\t\t\t\t          ****   SELAMAT DATANG ADMIN     *****\n";
            cout<<"\t\t\t\t          ***         * * * * *             ***\n";
            cout<<"\t\t\t\t          =====================================\n";
         getch();
         pembukaan()         ;
      }
      void pembukaan(void){
            awal:               
               cout<<"\n";              
               cout<<"\t\t\t\t====================== PILIHAN MENU =====================\n";
               cout<<"\t\t\t\t|                                                       |\n";
               cout<<"\t\t\t\t|               1. Masukkan data                        |\n";
               cout<<"\t\t\t\t|               2. Hapus Data                           |\n";
               cout<<"\t\t\t\t|               3. Lihat Data (Baru Diisi)              |\n";
               cout<<"\t\t\t\t|               4. Edit Data                            |\n";
               cout<<"\t\t\t\t|               5. Simpan Data Ke Database              |\n";
               cout<<"\t\t\t\t|               6. Lihat Data Di Database               |\n";
               cout<<"\t\t\t\t|               7. Keluar                               |\n";
               cout<<"\t\t\t\t=========================================================\n";
               cout<<"\t\t\t\t\t\tMasukkan Pilihan : ";
               try{
                  cin>>pilih;
                  if(cin.fail()){
                     throw "\t\t\t\tINPUT ANGKA !";
                  }                                    
               }catch(const char* r){
                  cout << r << endl;
                  system("PAUSE");
                  exit(0);
               }
               
                if(pilih ==1)
                  {system("cls");inputdata();goto awal;}
                else if(pilih ==2)
                  {system("cls");hapusdata();goto awal;}
                else if(pilih ==3)
                  {system("cls");lihatdata();goto awal;}               
                else if(pilih ==4)
                  {system("cls");editdata();goto awal;}
                else if(pilih==5){                      
                    tuliscsv();
                    cout << "\nData Anda Sudah Disimpan";
                    getch();
                    goto awal;
                }                
               else if(pilih == 7)                  
                  {system("cls");
                  cout<<"\n\n\n\n\n\n\n\n                     APAKAH ANDA YAKIN KELUAR DARI PROGRAM??\n\n";
                  cout<<"                         [Y]                         [N]                  \n"<<endl;
                  cout<<"                                         ";
                  try{
                     cin>>w;
                     if(cin.fail()){
                        throw "\t\t\t\tINPUT HURUF !";
                     }
                  }catch(const char* e){
                     cout << e << endl;
                     getch();
                     exit(0);
                  }                  
                  if(w=='y'||w=='Y')
                  {system("cls");
                  cout<<"\t\t\t\t      -- PROGRAM SELESAI -- \n";     
                  cout<<"\t\t\t\t ******************************\n";                  
                  penutupan();
                  }
                  else if(w=='n'||w=='N')
                        {system("cls");goto awal;}}
               else if(pilih < 1 || pilih > 6)
                  {system("cls");cout<<"\t\n\n\nPilihan 1-5:";getch();system("cls");goto awal;}
      }      
      
      void penutupan(void){
         cout<<"\n";
         cout<<"\t\t\t\t              >    o     \n";
         cout<<"\n";
         cout<<"\t\t\t\t                U       \n";
         cout<<"\n";
         cout<<"\t\t\t\t          Terima Kasih\n"; 
         cout<<"\t\t\t\t ==============================\n";         
      }
};


class tuliscsv{
    public:    
    void bacatulis(void){
         char isi[100], kluar[100], nama[90], harga[100];
         
         
         int i=0;      
         for(i; i < veknama.size() ; i++){
            masukan << veknama[i] << ", " << vekharga[i] << ", " << vekstok[i] << endl;
         }
         masukan.close();
      }
};

class prosesdata{
   protected:
      string nama;      
      int i,j, harga, stok;
      int x,y;
   public:
      void inputdata()  
      {    
         cout<<"\n\t\t\t\tJumlah Data Yang Akan diinput :  ";
         try{
            cin>>b;
            if(cin.fail()){
               throw "\t\t\t\t\tInput Angka !";
            }
         }catch(const char* e){
            cout << e << endl;
            getch();
            exit(0);
         }      
         d=0;
         for(c=0;c<b;c++){
         d=d+1;
         cout<<"\n";
         cout<<"\t\t\t\t          Data ke-"<<d<<endl; 
         cout<<"\t\t\t\t          ============\n";        
         cout<<"\t\t\t\t          | Nama Barang\t ";getline(cin.ignore(), nama);
         veknama.push_back(nama);
         cout<<"\t\t\t\t          | Harga Barang: ";
         try{
            cin>>harga; 
            if(cin.fail()){
               throw "\t\t\t\t\tInput Angka !";
            }
         }catch(const char* e){
            cout << e;
            getch();
            exit(0);
         }
         
         vekharga.push_back(harga);
         cout<<"\t\t\t\t          | Stok Barang\t: ";
         try{
            cin>>stok; 
            if(cin.fail()){
               throw "\t\t\t\t\tInput Angka !";
            }
         }catch(const char* e){
            cout << e;
            getch();
            exit(0);
         }
         vekstok.push_back(stok);
         a++;}system("cls");         
      }

   void lihatdata()
   {      
      if(veknama.size() == 0){
         cout << "\t\t\t\tSilahkan Masukkan Data Terlebih Dahulu" << endl;
         system("PAUSE");
         system("cls");
         inputdata();
      }else{
         cout<<"\t\t\t\t===============================================================================\n";
         cout<<"\t\t\t\t|                             Tampilkan Data                                   \n ";
         cout<<"\t\t\t\t===============================================================================\n";
         cout<<"\t\t\t\t|NO\t||\tNama\t\t||\tHarga\t||\tStok\t||\n";
         j=0;
         for(i=0;i<a;i++)
         {
            j=j+1;
            cout<<"\t\t\t\t===============================================================================\n";
            cout<<"\t\t\t\t|"<<j<<"\t||";             
            cout << veknama[i]<< "\t\t||" << vekharga[i] << "\t\t||" << vekstok[i] << "\t\t||" << endl;         
         }
         cout<<"\n\t\t\t\t===============================================================================\n";getch();system("cls");
      }      
   }

   void hapusdata()
   {            
      if(veknama.size() == 0){
         cout << "\t\t\t\tSilahkan Masukkan Data Terlebih Dahulu" << endl;
         system("PAUSE");
         system("cls");
         inputdata();
      }
      else{
         cout<<"\n\n\n\n\n\n";
         cout<<"\t\t\t\t\t\tHapus data ke-";
         cout<<"\t\t\t\t   ===============\n";
         try{
            cin>>x;
            if(cin.fail()){
               throw "\t\t\t\t\tInput Angka !";
            }
         }catch(const char* r){
            cout << r << endl;
            getch();
            exit(0);
         }
         if(x > a){
            cout << "\t\t\t\tMaaf! Data Yang Ingin Anda Hapus Tidak Terdaftar!\n";
            getch();
         }
         else{
            veknama.resize(a- 1);
            vekharga.resize(a - 1);
            vekstok.resize(a - 1);
            y=x-1;
            a--;
            for(int i=y;i<a;i++)
            {               
               j = j + 1;
               veknama[i] = veknama[i + 1];
               vekharga[i] = vekharga[i + 1];
               vekstok[i] = vekstok[i + 1];
            }
            system("cls");
            cout<<"\t\t\t\t  Data ke-"<<x<<" Terhapus   \n";
            cout<<"\t\t\t\t+++++++++++++++++++++++++++ \n";
            getch();system("cls");
         }      
      }      
   }

   void editdata(){
      int k,l;
      if(veknama.size() == 0){
         cout << "\t\t\t\tSilahkan Masukkan Data Terlebih Dahulu" << endl;
         system("PAUSE");
         system("cls");
         inputdata();
      }else{
         lihatdata();
         cout << endl;
         cout<<"\t\t\t\tMasukan Nomor Berapa Barang  yang akan diedit : ";
         try{
            cin>>k;
            if(cin.fail()){
               throw "\t\t\t\t\tInput Angka !";
            }            
         }catch(const char* r)         {
            cout << r << endl;
            getch();
            exit(0);
         }
         if(k <= a){         
            l=k-1;
            cout<<"\n";
            cout<<"\t\t\t\t      ISI DATA YANG BARU: \n";
            cout<<"\t\t\t\t    ------------------------\n";            
            cout<<"\t\t\t\t   | Nama Baru\t: ";getline(cin.ignore(), nama);;
            veknama[k - 1] = nama;
            cout<<"\t\t\t\t   | Harga Baru\t: ";
            try{
            cin >> harga;
            if(cin.fail()){
               throw "\t\t\t\t\tInput Angka !";
            }            
         }catch(const char* r)         {
            cout << r << endl;
            getch();
            exit(0);
         }
            vekharga[k - 1] = harga;
            cout<<"\t\t\t\t   | Stok Baru\t: ";
            try{
            cin>>stok;
            if(cin.fail()){
               throw "\t\t\t\t\tInput Angka !";
            }            
         }catch(const char* r)         {
            cout << r << endl;
            getch();
            exit(0);
         }
            vekstok[k - 1] = stok;
            lihatdata();
         }      
         else if(k < 0 || k > a){
            cout << "\t\t\t\tData Yang Ingin Anda Edit Tidak Terdaftar!\n";
            getch();         
         }
      }      
   }
};

class user{
    protected: 
        string text, token1, token2, token3;
        int jumlah = 0, jumlahbarang = 0, hargabarang, stokbarang, beli, id, idawal;
    public:
    void Ambil(){        
       
        if(baca.is_open()){            
            while(getline(baca, text)){
                istringstream ss(text);
                                
                getline(ss, token1, ',');                
                nama.push_back(token1);               
                getline(ss, token2, ',');                
                hargabarang = atoi(token2.c_str());
                harga.push_back(hargabarang);
                getline(ss, token3, ',');                
                stokbarang = atoi(token3.c_str());
                stok.push_back(stokbarang);
                jumlahbarang++;                
            }                     
            baca.close()               ;
        }   
        else{
            cout << "\t\t\t\tFile Tidak Dapat Dibuka !" << endl;
            system("PAUSE");
        }

    }
    void Lihat(){
        int r = 1;
        cout << "\t\t\t\tBarang : \n";
        cout << "\t\t\t\tNomor | Nama | Harga | Stok\n";
        for(int i = 0; i < jumlahbarang; i++){
            cout << r << " | ";
            cout << nama[i] << " | " << harga[i] << " | " << stok[i] << endl;            
            r++;
        }
    }
    void Belanja(){                                 
        cout<<"\n\t\t\t\tJumlah Jenis Barang yang ingin dibeli:";
        try{
            cin>>jumlah;
            if(cin.fail()){
                throw "\t\t\t\tInput Angka";
            }
        }catch(const char* e){
            cout << e << endl;
            getch();
            exit(0);
        }
        if(jumlah > jumlahbarang){
            cout<<"\t\t\t\tMaaf,Jumlah yang Anda masukkan melewati batas maksimum barang yang tersedia!" << endl;
            getch();
            exit(0);
        }
        else if(jumlah < 1){
            cout << "\t\t\t\tSilahkan Pilih Lebih Dari 1";
            exit(0);
        }
        else{
            awalbeli:
            for(int i=1; i<=jumlah; i++)
            {   
                idawal = 0;
                cout<<"\t\t\t\tMasukkan Nomor Barang:";
                try{
                    cin>>id;
                    if(cin.fail()){
                        throw "\t\t\t\tInput Angka !";
                    }                                            
                }catch(const char* e){
                    cout << e << endl;
                    getch();
                    exit(0);
                }
                if(id < 0 || id > jumlahbarang){
                    cout << "\t\t\t\tNomor Barang yang Anda Pilih Tidak Terdaftar\n";
                    system("pause");
                    goto awalbeli;
                }else if(id == idawal){
                    cout << "\t\t\t\tSilahkan Pilih yang Lain Berikutnya !\n";
                    getch();
                    cout << "\t\t\t\tPemilihan Diulangi !\n";
                    getch();
                    goto awalbeli;   
                }
                else if(id != idawal){
                    idawal = id;
                }
                
                cout<<"\t\t\t\tMau beli berapa nih : " ;
                try{
                    cin>>beli;
                    if(cin.fail()){
                        throw "\t\t\t\tInput Angka !";
                    }
                }catch(const char* e){
                    cout << e << endl;
                    getch();
                    exit(0);
                }
                if(beli == 0){
                    cout << "\t\t\t\tSilahkan Masukkan Angka Lebih Besar Dari 0 !";
                    goto awalbeli;   
                }
                else if(beli < 0){
                    cout << "\t\t\t\tSilahkan Masukkan Angka Lebih Besar Dari 0 !";
                    goto awalbeli;   
                }
                else if(beli > stok[id - 1]){
                    cout << "\t\t\t\tStok yang Anda Minta Melebihi Batas";
                    goto awalbeli;   
                }                
                else{
                    keranjang();
                }                
            }                        
            }            
            cout << "\t\t\t\tData Anda Sudah Disimpan !";
            getch();
            section();        
        }        
    
    void keranjang()
    {
        int k = 0;

        cout<<"\n\t\t\t\t                 KERANJANG      \n";
        cout<<"\t\t\t\t=================================================================================\n";
        cout<<"\t\t\t\tNama Barang | Jumlah Barang | Total Harga"<<'\n';                                      
        cout <<"\t\t\t\t" << nama[id - 1] << "| " << beli << " | Rp. " << beli * harga[id - 1] << endl;
        cout<<"\t\t\t\t=================================================================================\n";
        getch();
        keranjangnama.push_back(nama[id - 1]);
        keranjangbeli.push_back(beli);
        keranjangharga.push_back(harga[id - 1] * beli);                
        
    }
    void section(){
        int choice, r = 1;     
        system("cls");
        awalsection:   
         cout<<"\n\t\t\t\t                 KERANJANG  BELANJA    \n";
        cout<<"\t\t\t\t=================================================================================\n";
        cout<<"\t\t\t\tNO | Nama | Jumlah | Total Harga"<<'\n';
        for(int i = 0; i < jumlah ; i++){
            cout << "\t\t\t\t" <<  r << " | ";
            cout << keranjangnama[i] << " | ";
            cout << keranjangbeli[i] << " | ";
            cout << keranjangharga[i] << endl;
            r++;
        }                                              
        cout<<"\t\t\t\t=================================================================================\n";

        cout<<"\t\t\t\t=======================\n";                
        cout<<"\t\t\t\t|    1.Ganti Barang    |\n";
        cout<<"\t\t\t\t|    2.Checkout        |\n";
        cout<<"\t\t\t\t|    3.Exit            |\n";
        cout<<"\t\t\t\t========================\n";
        cout<<"\t\t\t Pilih Menu : ";
        try{
            cin>>choice;
            if(cin.fail()){
                throw "\t\t\t\tInput Angka !";            
            }
        }catch(const char* e){
            cout << e << endl;
            system("PAUSE");
            exit(0);
        }
        if(choice == 1){
            cout << "\t\t\t\tSilakan Dilihat Lagi !" << endl;
            getch();
            system("cls");
            Lihat();
            Belanja();
            goto awalsection;
        }            
        else if(choice == 2)            
            {pembayaran();}
        
        else if(choice == 3)
            pilihan();
        else if(choice < 1 || choice > 3){
            cout<<"\t\t\t\tMaaf, Cukup masukkan angka 1,2, 3 saja!";        
            goto awalsection;
        }            
    }
    
    void pembayaran(){
        awalpembayaran:        
        int bayar=0, uang, kembalian=0;
        string name;        

      for(int i=0; i<jumlah; i++){
          bayar+=keranjangharga[i];
      }
      cout<<"\t\t\t\tMasukkan Nama Anda: ";
      getline(cin.ignore(), name);
      cout << "\n\t\t\t\tTotal Belanja Anda : " << bayar << endl;
      cout<<"\t\t\t\tMasukkan jumlah uang anda: ";
        try{
            cin >> uang;
            if(cin.fail()){
                throw "\t\t\t\tInput Angka !";
            }
        }catch(const char* e){
            cout << e << endl;
            system("pause");
            goto awalpembayaran;
        }
      if(uang<bayar){
          cout<<"\t\t\t\tMaaf, Uang Anda kurang!\n";
          system("pause");
          goto awalpembayaran;
      }
      else if(uang==0){
          cout<<"\t\t\t\tTolong Masukkan jumlah uang Anda!\n";
          system("pause");
          goto awalpembayaran;
      }
      else{
          kembalian= uang - bayar;
          cout<<"\n\n";
          cout<<"\t\t\t\t       Bukti Transaksi Belanja              \n";
          cout<<"\t\t\t\t--------------------------------------------\n";
          cout<<"\t\t\t\t    Nama Pembeli:"           <<name     <<"|\n";
          cout<<"\t\t\t\t    Jumlah uang Anda Rp"     <<uang     <<"|\n";
          cout<<"\t\t\t\t    Total Belanja Anda Rp"   <<bayar    <<"|\n";
          cout<<"\t\t\t\t    Kembalian Uang Anda Rp"  <<kembalian<<"|\n";
          cout<<"\t\t\t\t---------------------------------------------\n";
          
          cout<<"\t\t\t\t            TERIMA KASIH !!!              \n";
          cout<<"\t\t\t\t                 ===                      \n";
          getch();
          exit(0);
      }
    }

    void pilihan(){
        cout << "\t\t\t\tKamu yakin ingin keluar?\n";
        if (jumlah == 0)
        {
            cout<<"\t\t\t\tKamu yakin ingin keluar?Barang Anda belum tersimpan";
            getch();
            keranjang();
        }
        cout << "\t\t\t\t1 - Keluar | 2/etc - Kembali\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "\t\t\t\tTerimakasih atas kunjungannya! Selamat datang kembali dilain waktu! :)\n";
            cout<<"\t\t\t\t             ===========================================\n";
            system("pause");
            exit(0);
        }
        else
        {
            section();
        }
    }
    
};

class menu: public user{
    private:
    int pilih;
    public:
    void menuuser(void){        
        awal:        
        system("cls");
        Ambil();
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t-----------------------------"<<'\n';
        cout<<"\t\t\t\t\t\t|     ===== Menu =====      |"<<'\n';
        cout<<"\t\t\t\t\t\t|      1.Belanja            |"<<'\n';        
        cout<<"\t\t\t\t\t\t|      2.Exit               |"<<'\n';
        cout<<"\t\t\t\t\t\t----------------------------"<<'\n';
        cout<<"\t\t\t\t\t\t Pilih Menu:";        
        try{
            cin>>pilih;
            if(cin.fail()){
                throw "\t\t\t\tMASUKKAN ANGKA !";                
            }
        }catch(const char* e){
            cout << e << endl;
            system("PAUSE");
            exit(0);
        }        
        if(pilih==1){
            system("cls");
            cout<<"\t\t\t\t==============================================\n";
            cout<<"\t\t\t\t          --SELAMAT BERBELANJA-- \n"; 
            cout<<"\t\t\t\t==============================================\n";            
            Lihat();
            Belanja();            
            goto awal;
        }        
        else if(pilih==2){
            cout<<"\n";
            cout<<"\t\t\t\tGood By! Terima Kasih Atas Waktunya :)"<<endl;
            cout<<"\t\t\t\t     =========================        "<<endl;
            system("PAUSE");
            exit(0);
        }
        else if(pilih < 1 || pilih > 2){
            cout<<"\t\t\t\tMasukkan 1, dan 2 saja!" << endl;
            system("PAUSE");
            cout << endl;
            goto awal;
        }
    }
};

class level : public menu,proses{
    private:
    int option, pilihAdmin;
    string username, password;
    public:
    level(){
        system("cls");
           cout<<"\t\t\t\t          ========================================\n";
           cout<<"\t\t\t\t          ****   SELAMAT DATANG DI TOKO KAMI *****\n";
           cout<<"\t\t\t\t          ***         * * * * * * * * *        ***\n";
           cout<<"\t\t\t\t          ========================================\n";
        getch();
        cout<<"\n";                       
        cout << "\t\t\t\t                1. User" << endl;
        cout << "\t\t\t\t                2. Admin" << endl;
        cout << "\t\t\t\t             Apakah Status Anda: ";        
        try{
            cin>>option;
            if(cin.fail()){
                throw "\t\t\t\tINPUT ANGKA";
            }
        }catch(const char* e){
            cout << e << endl;
            system("pause");
            exit(0);
        }
        if (option < 1 && option > 2)
                throw "\t\t\t\tPilihan tidak sesuai";
        else{
            if(option == 1){
                menuuser();
            }
            else if(option == 2){
                system("cls");
                cout << "1. Daftar Admin\n2. Login Admin ";
                try{
                    cin >> pilihAdmin;
                    if(cin.fail()){
                        throw "Input Angka!";
                    }
                }catch(const char* e){
                    cout << e << endl;
                    system("pause");
                    exit(0);
                }
                if(pilihAdmin == 1){
                    write();
                    prosesadmin();             
                }
                else if(pilihAdmin == 2){
                    AdminLogin();
                }
                else{
                    cout << "Pilihan Anda Tidak Dapat Dikonfirmasi !";
                    getch();
                    exit(0)                    ;
                }
            }
        }            
    }    

    void AdminLogin()
    {
        system("cls");
        cout << "Login Admin\n";
        cout << "Username:\t ";
        getline(cin.ignore(),username);
        cout << "Password:\t ";
        password = "";
        char c;
        while ((c = getch()) != 13)
        {
            if (c == 8 && password.length() > 0)
            {
                cout << '\b' << ' ' << '\b';
                password.erase(password.length() - 1, 1);
            }

            else if (c != 8 && password.length() <= 24 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
            {
                password += c;
                cout << '*';
            }
        }        
        cekData();
        this->auth(this->username, this->password);        
    }

    void cekData()
    {        
        string line;        
        string cell, token1;       
        int i = 0, r = 0;        
        while (getline(datum, line))
        {
            stringstream lineStream(line);                 
            getline(lineStream, cell, ',');
            parsedName.push_back(cell);
            getline(lineStream, token1, ',');
            parsedPas.push_back(token1);            
            akun.insert(pair<string, string>(parsedName[i], parsedPas[r]));
            r++;i++;            
        }        
    }
    void auth(string userName, string userPassword)
    {
        int i = 0;
        string pw;        
        for(i;i<parsedName.size();i++){
            if (akun.find(userName)->first == userName)
            {
                pw = (akun.find(userPassword)->second);
                if (userPassword.compare(pw) == 0)
                {
                    cout <<endl<< "Login berhasil!\n"<<endl;
                    system("pause");
                    prosesadmin();                    
                }
                else if (userPassword.compare(pw) != 0)
                {
                    cout <<endl<< "Password salah!\n";
                }
                }
            else{
                cout << "\nData Tidak Ditemukan !\n";
            }        
        }        
    }
     void write()
    { 
        string username;
        string password;

        system("cls");
        cout << "Daftar Admin\n";
        cout << "Username:\t ";
        getline(cin.ignore(),username);
        cout << "Password:\t ";
        getline(cin, password);        
        fout << username << "," << password << "\n";        
        cout << "\nData Sudah Disimpan !";
        getch();
        fout.close();
    };
};


int main(){
    level m;
    
    return 0;
}