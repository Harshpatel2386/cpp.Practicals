#include <iostream>
#include <cmath>
using namespace std;

class LoanDetails {
private:
    int loanId,P,T;
    float R,EMI;
    string applicantName;

public:
    void addDetails(string name,int id,int LoanAmount,int tenure,float interestRate);
    int searchId(int id) {
        return (loanId==id)?1:0;
    }
    void calculateEMI();
    void displayDetails();
};

void LoanDetails::addDetails(string name,int id,int LoanAmount,int tenure,float interestRate) {
    applicantName=name;
    loanId=id;
    P=LoanAmount;
    T=tenure;
    R=interestRate/(12*100);
    calculateEMI();
}

void LoanDetails::calculateEMI() {
    if(R!=0) {
        EMI=(P*R*pow((1.0+R),T))/(pow((1.0+R),T)-1.0);
    } else {
        EMI=P/T;
    }
}

void LoanDetails::displayDetails() {
    cout<<"DETAILS FOR "<<loanId<<endl;
    cout<<"Loan ID: "<<loanId<<endl;
    cout<<"Applicant Name: "<<applicantName<<endl;
    cout<<"Total Loan Amount: "<<P<<endl;
    cout<<"Interest Rate: "<<R*12*100<<"%"<<endl;
    cout<<"Tenure (Months): "<<T<<endl;
    cout<<"EMI: "<<EMI<<endl;
}

int main() {
    LoanDetails Loan[25];
    string name;
    int id,LoanAmount,tenure;
    float interestRate;
    int count=0,choice;

start:
    if(count==0) {
        cout<<"Enter the Loan ID: ";
        cin>>id;
        cin.ignore();
        cout<<"Enter the applicant's name: ";
        getline(cin,name);
        cout<<"Enter the loan amount: ";
        cin>>LoanAmount;
        cout<<"Enter the interest rate (in % per annum): ";
        cin>>interestRate;
        cout<<"Enter the tenure (in months): ";
        cin>>tenure;
        Loan[count].addDetails(name,id,LoanAmount,tenure,interestRate);
        count++;
    } else {
        cout<<"\nENTER 1 TO ADD LOAN DETAILS\nENTER 2 TO DISPLAY LOAN DETAILS\nENTER 0 TO EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter the Loan ID: ";
                cin>>id;
                cin.ignore();
                cout<<"Enter the applicant's name: ";
                getline(cin,name);
                cout<<"Enter the loan amount: ";
                cin>>LoanAmount;
                cout<<"Enter the interest rate (in % per annum): ";
                cin>>interestRate;
                cout<<"Enter the tenure (in months): ";
                cin>>tenure;
                Loan[count].addDetails(name,id,LoanAmount,tenure,interestRate);
                count++;
                goto start;
            case 2:
                cout<<"Enter Loan ID to search: ";
                cin>>id;
                int i;
                    for(i=0;i<count;i++) {
                    if(Loan[i].searchId(id)) {
                        Loan[i].displayDetails();
                        goto start;
                    }
                }
                if(i==count)cout<<"Loan ID not found!"<<endl;
                goto start;
            case 0:
                cout<<"Thank You!"<<endl;
                cout<<"Harsh Hirpara- 24CE040"<<endl;
                return 0;
            default:
                cout<<"Enter a valid choice!"<<endl;
                goto start;
        }
    }
    goto start;
}