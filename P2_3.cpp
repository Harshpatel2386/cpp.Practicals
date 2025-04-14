#include<iostream>
using namespace std;

class BankAccount{
    string accHoldername;
    int accNumber;
    float balance;

public:
    BankAccount(){}  

    BankAccount(string name,int number,float balanceAmount){
        accHoldername=name;
        accNumber=number;
        balance=balanceAmount;
    }

    void deposit(float amount){
        balance+=amount;
        cout<<"Deposit Successful! Current Balance:"<<balance<<endl;
    }

    void withdraw(float amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawal Successful! Current Balance:"<<balance<<endl;
        }else{
            cout<<"Not enough balance!"<<endl;
        }
    }

    void displayAccDetails(){
        cout<<"Account Holder Name:"<<accHoldername<<endl;
        cout<<"Account Number:"<<accNumber<<endl;
        cout<<"Current Balance:"<<balance<<endl;
    }

    int getAccNumber(){
        return accNumber;
    }
};

int main(){
    string name;
    int number,choice,accountNumber;
    float balanceAmount,amount;
    int count=0,i;
    BankAccount* B[15];  

    create:
        cout<<"Enter Account Holder Name:";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Account Number:";
        cin>>number;
        cout<<"Enter Initial Balance:";
        cin>>balanceAmount;

        B[count]=new BankAccount(name,number,balanceAmount);
        count++;

        cout<<"\nDo you want to create another account? (1 for yes / 0 for no):";
        cin>>choice;

        if(choice==1){
            goto create;
        }else{
            cout<<"Accounts Created Successfully!\n"<<endl;
        }

    operation:
        cout<<"\nEnter Account Number to Perform Operations:";
        cin>>accountNumber;

        for(i=0;i<count;i++){
            if(B[i]->getAccNumber()==accountNumber){
                cout<<"ACCOUNT FOUND!\n";
                cout<<"ENTER 1 FOR DEPOSIT\nENTER 2 FOR WITHDRAW\nENTER 3 FOR DISPLAY DETAILS\nENTER 0 FOR EXIT\n";
                cout<<"Enter your choice:";
                cin>>choice;

                switch(choice){
                    case 1:
                        cout<<"Enter Amount to Deposit:";
                        cin>>amount;
                        B[i]->deposit(amount);
                        break;

                    case 2:
                        cout<<"Enter Amount to Withdraw:";
                        cin>>amount;
                        B[i]->withdraw(amount);
                        break;

                    case 3:
                        cout<<"\nAccount Details:\n";
                        B[i]->displayAccDetails();
                        break;

                    case 0:
                        cout<<"Thank you!"<<endl;
                        cout<<"Harsh Hirpara- 24CE040"<<endl;
                        return 0;

                    default:
                        cout<<"Invalid Choice!"<<endl;
                }
                goto operation;
            }
        }
        cout<<"Account Not Found!\n";
        goto operation;
        return 0;
}