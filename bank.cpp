#include <iostream>
using namespace std;


class Bank {
private:
    int acno;
    char name[30];
    long balance;

public:
    void OpenAccount()
    {
        cout << "masukkan nomor akun : ";
        cin >> acno;
        cout << "masukkan nama anda : ";
        cin >> name;
        cout << "saldo anda : ";
        cin >> balance;
    }
    void ShowAccount()
    {
        cout << "nomor akun : " << acno << endl;
        cout << "Nama : " << name << endl;
        cout << "saldo : " << balance << endl;
    }
    void Deposit()
    {
        long amt;
        cout << "masukkan jumlah yang ingin anda setor ? ";
        cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()
    {
        long amt;
        cout << "masukkan yang ingan anda tarik ? ";
        cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            cout << "saldo anda kurang..." << endl;
    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (acno == a) {
        ShowAccount();
        return (1);
    }
    return (0);
}
