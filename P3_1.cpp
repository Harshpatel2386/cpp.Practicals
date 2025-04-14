#include <iostream>
using namespace std;

class Employee {
    string name;
    double basicSalary;
    double bonus;
public:
    Employee(string n,double bs,double b=0) {
        name=n;
        basicSalary=bs;
        bonus=b;
    }
    inline double calculateTotalSalary() {
        return basicSalary+bonus;
    }
    void display() {
        cout<<"Name: "<<name<<"\nBasic Salary: "<<basicSalary<<"\nBonus: "<<bonus<<"\nTotal Salary: "<<calculateTotalSalary()<<endl<<endl;
    }
};

int main() {
    Employee *employees[15];
    string name;
    char bonusChoice;
    int count=0,salary,bonus;
    char choice;

    do {
        cout<<"Enter name for Employee "<<count+1<<": ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Basic Salary: ";
        cin>>salary;
        cout<<"Do you want to enter custom bonus? (Y/N): ";
        cin>>bonusChoice;
        if(bonusChoice=='Y'||bonusChoice=='y') {
            cout<<"Enter Bonus: ";
            cin>>bonus;
            employees[count]=new Employee(name,salary,bonus);
        } else {
            employees[count]=new Employee(name,salary);
        }
        count++;
        cout<<"Do you want to add another Employee? (Y/N): ";
        cin>>choice;
    } while(choice=='Y'||choice=='y');

    cout<<"\nEMPLOYEE DETAILS\n";
    for(int i=0;i<count;i++) {
        employees[i]->display();
    }

    for(int i=0;i<count;i++) {
        delete employees[i];
    }

    cout<<"Harsh Hirpara- 24CE040"<<endl;
    return 0;
}