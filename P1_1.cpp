#include <iostream>
using namespace std;

class BankAccount
{
public:
    string HolderName;
    int accountNumber,balance;

    void deposit(int amount)
    {
        if(amount>0)
        {
            balance+=amount;
        }
    }
    void withdraw(int amount)
    {
        if(amount>0 && amount<balance)
        {
            balance-=amount;
        }
        else if(amount>balance)
        {
            cout<<"Not enough balance!"<<endl;
        }
    }
    void display_balance()
    {
        cout<<"Current Balance: "<<balance;
    }
};

int main()
{
    BankAccount B1;
    B1.balance=10000;
    int amount;
    int choice;

    cout<<"Enter your name: ";
    cin>>B1.HolderName;
    cout<<"Enter your account number: ";
    cin>>B1.accountNumber;

    cout<<"For DEPOSIT Enter 1"<<endl<<"For WITHDRAW Enter 2"<<endl<<"For CHECKING CURRENT BALANCE Enter 3"<<endl<<"For EXIT Enter 4"<<endl;
    do{
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter amount for Deposit: ";
            cin>>amount;
            B1.deposit(amount);
            break;
        case 2:
            cout<<"Enter amount for Withdraw: ";
            cin>>amount;
            B1.withdraw(amount);
            break;
        case 3:
            B1.display_balance();
            break;
        case 4:
            cout<<"\nThank you!"<<endl;
            break;
        default:
            cout<<"Enter valid choice!"<<endl;
        }
    }
    while(choice!=4);

    cout<<"Ronit Padia - 24CE069"<<endl;
    return 0;
}