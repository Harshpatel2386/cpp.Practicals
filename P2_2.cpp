#include <iostream>
#include <string.h>
using namespace std;

class student {
private:
    int rollNumber,marks[3];
    string name;
public:
    student() {
        rollNumber=0;
        name="N/A";
        for(int i=0;i<3;i++) {
            marks[i]=0;
        }
    }
    student(string nm,int rn,int m[]) {
        name=nm;
        rollNumber=rn;
        for(int i=0;i<3;i++) {
            marks[i]=m[i];
        }
    }
    void displayDetails() {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollNumber<<endl;
        for(int i=0;i<3;i++) {
            cout<<"Marks for subject "<<i+1<<": "<<marks[i]<<endl;
        }
    }
    void calculateAverage() {
        int sum=0;
        for(int i=0;i<3;i++) {
            sum+=marks[i];
        }
        float avg=(float)sum/3;
        cout<<"Average marks: "<<avg<<endl;
    }
};

int main() {
    student *s=new student[15];
    int rn,m[3],i=0;
    string nm;
    char choice;
    do {
        cout<<"ENTER THE DETAILS FOR STUDENT "<<i+1<<endl;
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,nm);
        cout<<"Enter Roll number: ";
        cin>>rn;
        for(int j=0;j<3;j++) {
            cout<<"Enter marks for subject "<<j+1<<": ";
            cin>>m[j];
        }
        s[i]=student(nm,rn,m);
        i++;
        cout<<"Do you want to add another student? (y/n): ";
        cin>>choice;
        cout<<endl;
    } while(choice=='y'||choice=='Y');

    for(int j=0;j<i;j++) {
        cout<<"\nDATA OF STUDENT "<<j+1<<endl;
        s[j].displayDetails();
        s[j].calculateAverage();
    }
    cout<<"Harsh Hirpara- 24CE040"<<endl;
    delete[] s;
    return 0;
}
