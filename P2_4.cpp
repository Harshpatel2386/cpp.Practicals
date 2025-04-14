#include <iostream>
#include <string.h>
using namespace std;

class itemStock {
    private:
        string itemName;
        int itemId,itemPrice,quantity;
    public:
        int searchId(int id) {
            return (itemId==id)?1:0;
        }
        void additem(int id,string name,int price,int qty) {
            itemId=id;
            itemName=name;
            itemPrice=price;
            quantity=qty;
        }
        void addstock(int qty) {
            quantity+=qty;
            cout<<"\nStock updated successfully!\nNew quantity for "<<itemName<<": "<<quantity<<endl;
        }
        void sellitem(int qty) {
            if(qty<=quantity) {
                quantity-=qty;
                cout<<"\nStock sold successfully!\nRemaining quantity for "<<itemName<<": "<<quantity<<endl;
            } else {
                cout<<"\nNot enough stock available!"<<endl;
            }
        }
        void displayItems() {
            cout<<"\nITEM DETAILS FOR "<<itemId<<endl;
            cout<<"Item ID: "<<itemId<<endl;
            cout<<"Item Name: "<<itemName<<endl;
            cout<<"Item Price: "<<itemPrice<<endl;
            cout<<"Item Quantity: "<<quantity<<endl;
        }
};

int main() {
    itemStock item[25];
    string name;
    int id,price,qty;
    int choice,count=0,i;

    do {
        cout<<"1.Add New Item"<<endl;
        cout<<"2.Update Stock"<<endl;
        cout<<"3.Sell Item"<<endl;
        cout<<"4.Display All Items"<<endl;
        cout<<"0.Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter Item ID: ";
                cin>>id;
                cin.ignore();
                cout<<"Enter Item Name: ";
                getline(cin,name);
                cout<<"Enter Price: ";
                cin>>price;
                cout<<"Enter Quantity: ";
                cin>>qty;
                item[count].additem(id,name,price,qty);
                count++;
                cout<<"\nItem added successfully!"<<endl;
                break;
            case 2:
                cout<<"Enter the Item ID to update stock: ";
                cin>>id;
                for(i=0;i<count;i++) {
                    if(item[i].searchId(id)) {
                        cout<<"Enter the quantity to add: ";
                        cin>>qty;
                        item[i].addstock(qty);
                        break;
                    }
                }
                if(i==count)cout<<"\nItem not found!"<<endl;
                break;
            case 3:
                cout<<"Enter the Item ID to sell: ";
                cin>>id;
                for(i=0;i<count;i++) {
                    if(item[i].searchId(id)) {
                        cout<<"Enter the quantity to sell: ";
                        cin>>qty;
                        item[i].sellitem(qty);
                        break;
                    }
                }
                if(i==count)cout<<"\nItem not found!"<<endl;
                break;
            case 4:
                if(count==0) {
                    cout<<"\nNo items available in stock!"<<endl;
                } else {
                    for(i=0;i<count;i++) {
                        item[i].displayItems();
                    }
                }
                break;
            case 0:
                cout<<"\nThank you for using the system!"<<endl;
                break;
            default:
                cout<<"\nInvalid choice!"<<endl;
        }
    } while(choice!=0);
    cout<<"Harsh 11Hirpara- 24CE040"<<endl;
}