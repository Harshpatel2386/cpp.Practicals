#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray() : size(0), capacity(2) {
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void addElement(int value) {
        if (size == capacity) resize();
        arr[size++] = value;
    }

    void removeElement(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;

    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);
    arr.addElement(40);

    cout << "Array elements: ";
    arr.display();

    arr.removeElement(2);
    cout << "Array after removal: ";
    arr.display();

    cout<<"HARSH_HIRPARA_24CE040";
    return 0;
}

