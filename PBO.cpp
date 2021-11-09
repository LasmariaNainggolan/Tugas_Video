#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool Login()
{
	string username, password, un, pw;

	cout<<"username: ";
	cin>>username;
	cout<<"password: ";
	cin>>password;

	ifstream read("data.txt",ios::app);
	getline(read, un);
	getline(read, pw);

	if(un == username && pw==password){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	int choice;

	cout<<"1. register\n2. Login\nYour choice: ";
	cin>>choice; 
	if(choice==1){
		string username, password;
		cout<<"select username: ";
		cin>>username;
		cout<<"select password: ";
		cin>>password;

		ofstream file;
		file.open("data.txt",ios::app);
		file<<username<<endl<<password;
		file.close();

		main();
	}

	else if(choice==2){
		bool status = Login();
		if(!status){
			cout<<"login gagal\n";
			system("PAUSE");
			return 0;
		}
		else
		{
			cout<<"berhasil";
			system("PAUSE");
			return 1;
		}
	}

}