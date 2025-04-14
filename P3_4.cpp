#include <iostream>
using namespace std;

template <typename T>
void displayElements(T arr[], int size)
{
    cout<<"Original elements: ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
void maxValue(T arr[], int size)
{
    T max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(max < arr[i]) max = arr[i];
    }
    cout<<"Max value: "<<max<<endl;
}

template <typename T>
void reverseCollection(T arr[], int size)
{
    for(int i = 0; i < size/2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }

    cout<<"Reversed collection: ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int choice;
    
    do{
        cout<<"Select data type:\n1. Integer\n2. Float\n3. Character\n4 to exit\nEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int arr[100], element;
                int i = 0;
                cout<<"Enter integers (enter 0 to stop):\n";
                while(true)
                {
                    cin>>element;
                    if(element == 0) break;
                    arr[i++] = element;
                }
                if(i == 0) break;
                displayElements(arr, i);
                maxValue(arr, i);
                reverseCollection(arr, i);
                break;
            }
    
            case 2:
            {
                float arr[100], element;
                int i = 0;
                cout<<"Enter float values (enter 0 to stop):\n";
                while(true)
                {
                    cin>>element;
                    if(element == 0.0) break;
                    arr[i++] = element;
                }
                if(i == 0) break;
                displayElements(arr, i);
                maxValue(arr, i);
                reverseCollection(arr, i);
                break;
            }
    
            case 3:
            {
                char arr[100], element;
                int i = 0;
                cout<<"Enter characters (enter ! to stop):\n";
                while(true)
                {
                    cin>>element;
                    if(element == '!') break;
                    arr[i++] = element;
                }
                if(i == 0) break;
                displayElements(arr, i);
                maxValue(arr, i);
                reverseCollection(arr, i);
                break;
            }
            
            case 4:
                cout<<"Thank you!"<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice!=4);
    cout<<"Harsh Hirpara- 24CE040"<<endl;
    return 0;
}