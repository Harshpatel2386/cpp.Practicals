#include <iostream>
using namespace std;

class Rectangle{
private:
    float length,width;
public:
    void setDimensions(float l, float w){
        length=l;
        width=w;
    }
    float area(){
        return length*width;
    }
    float perimeter(){
        return 2*(length+width);
    }
};

int main(){
    Rectangle *rectangles=new Rectangle[15];
    float l,w;
    int i=0;
    char choice;

    do{
        cout<<"Enter the length of rectangle "<<i+1<<": ";
        cin>>l;
        cout<<"Enter the width of rectangle "<<i+1<<": ";
        cin>>w;
        rectangles[i].setDimensions(l,w);
        cout<<"Area of rectangle "<<i+1<<": "<<rectangles[i].area()<<endl;
        cout<<"Perimeter of rectangle "<<i+1<<": "<<rectangles[i].perimeter()<<endl;
        cout<<"Do you want to add another rectangle? (y/n): ";
        cin>>choice;
        cout<<endl;
        i++;
    }while(choice=='y'||choice=='Y');

    delete[] rectangles;
    cout<<"Harsh Hirpara- 24CE040"<<endl;
    return 0;
}
