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


int main()
{
    Bank C[3];

    int found = 0, a, ch, i;
    for (i = 0; i <= 2; i++) {
        C[i].OpenAccount();
    }

    do {
        
        cout << "\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" << endl;

        
        cout << "silahkan pilih : ";
        cin >> ch;

        switch (ch) {
        case 1: 
            for (i = 0; i <= 2; i++) {
                C[i].ShowAccount();
            }
            break;
        case 2: 
            cout << "nomor akun ? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found)
                    break;
            }
            if (!found)
                cout << "Record not found " << endl;
            break;
        case 3: 
            cout << "nomor akun yang ingin anda setor? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Deposit();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 4: 
            cout << "nomor akun yang ingin anda tarik? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Withdrawal();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 5: 
            cout << "Have a nice day" << endl;
            break;
        default:
            cout << "Wrong Option" << endl;
        }
    } while (ch != 5);
    return 0;
}