#include <iostream>
#include <string.h>

using namespace std;

class product{
private:
    int pid,pquan,prate,ptotal;
    char pname[20];

public:
    void addProduct(char x[20],int y,int z)
    {
        strcpy(pname,x);
        pid=y;
        prate=z;
        pquan=1;
    }
    int searchProd(int searchID)
    {
        if(pid==searchID)
            return 1;
        else
            return 0;
    }
    void updateQuantity(int p)
    {
        pquan++;
    }
    int returnTotal()
    {
        return prate*pquan;
    }
};

int main()
{
    product p[30];
    int id,rate,prodCount=0;
    char name[20];
    int i,choice,totalAmount=0;

    bill:
    cout<<"Enter the name of the product: ";
    cin>>name;
    cout<<"Enter the ID of the product: ";
    cin>>id;
    cout<<"Enter the price of the product: ";
    cin>>rate;
    if(prodCount==0)
    {
        p[0].addProduct(name,id,rate);
        prodCount++;
    }
    else
    {
        for(i=0;i<prodCount;i++)
        {
            if(p[i].searchProd(id)==1)
            {
                break;
            }
        }
        if(i==prodCount)
        {
            p[i].addProduct(name,id,rate);
            prodCount++;
        }
        else{
            p[i].updateQuantity(rate);
        }
    }
    cout<<"Enter 1 to continue and 0 to exit the system!\n";
    cin>>choice;
    if(choice==1)
    {
        goto bill;
    }
    else
    {
        for(i=0;i<prodCount;i++)
        {
            totalAmount += p[i].returnTotal();
        }
        cout<<"-------------------------------------\n";
        cout<<"Total bill is: "<<totalAmount<<endl;
        cout<<"Thank You!\n";
    }
    cout<<"Harsh Hirpara- 24CE040"<<endl;
}