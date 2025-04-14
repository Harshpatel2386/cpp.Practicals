#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;
    static int totalAccounts;

public:
    BankAccount() {
        accountNumber = 0;
        name = "";
        balance = 0.0;
        totalAccounts++;
    }

    BankAccount(int accNum, string accName, double accBalance){
        accountNumber=accNum;
        name=accName;
        balance=accBalance;
        totalAccounts++;
    }
    void displayDetails() {
        cout<<"Account Number: "<<accountNumber<<"\nName: "<<name<<"\nBalance: "<<balance<<endl;
    }

    static void displayTotalAccounts() {
        cout<<"Total Accounts Created: "<<totalAccounts<<endl;
    }

    friend void transferMoney(BankAccount &from, BankAccount &to, double amount);
};

int BankAccount::totalAccounts = 0;

void transferMoney(BankAccount &from, BankAccount &to, double amount) {
    if (amount > from.balance) {
        cout<<"Transfer Failed! Insufficient Balance in Account: "<<from.accountNumber<<endl;
    } else {
        from.balance -= amount;
        to.balance += amount;
        cout<<"Transfer Successful! "<<amount<<" transferred from Account "<<from.accountNumber<<" to Account "<<to.accountNumber<<endl;
    }
}

int main() {
    BankAccount *accounts[20];
    int count = 0;
    int accountNumber,balance;
    string name;
    char choice;

    do {
        cout<<"Enter details for Account "<<count + 1<<endl;
        cout<<"Enter Account Number: ";
        cin>>accountNumber;
        cout<<"Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Initial Balance: ";
        cin>>balance;
        accounts[count] = new BankAccount(accountNumber, name, balance);
        count++;
        cout<<"Do you want to add another account? (Y/N): ";
        cin>>choice;
        cout<<endl;
    } while (choice == 'Y' || choice == 'y');

    cout<<"\nACCOUNT DETAILS\n";
    for (int i = 0; i < count; i++) {
        accounts[i]->displayDetails();
    }

    BankAccount::displayTotalAccounts();

    int fromIndex, toIndex;
    double amount;

    cout<<"\nMONEY TRANSFER\n";
    cout<<"Enter Sender Account Index (1 to "<<count<<"): ";
    cin>>fromIndex;
    cout<<"Enter Receiver Account Index (1 to "<<count<<"): ";
    cin>>toIndex;
    cout<<"Enter Amount to Transfer: ";
    cin>>amount;

    if (fromIndex >=1 && fromIndex <=count && toIndex >=1 && toIndex <=count) {
        transferMoney(*accounts[fromIndex - 1], *accounts[toIndex - 1], amount);
    } else {
        cout<<"Invalid account index!"<<endl;
    }

    cout<<"\nUPDATED ACCOUNT DETAILS\n";
    for (int i = 0; i < count; i++) {
        accounts[i]->displayDetails();
    }

    BankAccount::displayTotalAccounts();

    for (int i = 0; i < count; i++) {
        delete accounts[i];
    }

    cout<<"Harsh Hirpara- 24CE040"<<endl;
    return 0;
}
