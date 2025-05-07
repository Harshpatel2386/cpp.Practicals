#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}

    Point* move(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p(5, 10);
    p.display();

    p.move(3, 4)->move(-2, 1)->move(5, -3);

    p.display();

    cout<<"HARSH_HIRPARA_24CE040";
    return 0;
}

