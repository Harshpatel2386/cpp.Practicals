#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived Destructor\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;

    cout<<"HARSH_HIRPARA_24CE040";
    return 0;
}
