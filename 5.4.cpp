#include <iostream>
#include <iomanip>
#include <cmath> // For std::fabs
#include <limits> // For std::numeric_limits

using namespace std;

const float EPSILON = 0.01f; // Tolerance for floating-point comparison

class Fahrenheit; // Forward declaration

class Celsius {
    float temp;

public:
    Celsius(float t = 0.0f) : temp(t) {}

    float getTemp() const {
        return temp;
    }

    // Type conversion from Celsius to Fahrenheit
    operator Fahrenheit() const;

    // Equality comparison with Fahrenheit
    bool operator==(const Fahrenheit& f) const;
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 0.0f) : temp(t) {}

    float getTemp() const {
        return temp;
    }

    // Type conversion from Fahrenheit to Celsius
    operator Celsius() const {
        return Celsius((temp - 32.0f) * 5.0f / 9.0f);
    }

    // Equality comparison with Celsius
    bool operator==(const Celsius& c) const {
        return std::fabs((temp - 32.0f) * 5.0f / 9.0f - c.getTemp()) < EPSILON;
    }
};

// Implementation of type conversion from Celsius to Fahrenheit
Celsius::operator Fahrenheit() const {
    return Fahrenheit((temp * 9.0f / 5.0f) + 32.0f);
}

// Implementation of equality comparison with Fahrenheit
bool Celsius::operator==(const Fahrenheit& f) const {
    return std::fabs((temp * 9.0f / 5.0f) + 32.0f - f.getTemp()) < EPSILON;
}

int main() {
    float cTemp, fTemp;

    cout << fixed << setprecision(2); // Set output formatting

    cout << "Enter temperature in Celsius: ";
    while (!(cin >> cTemp)) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a numeric value for Celsius: ";
    }
    Celsius c1(cTemp);
    Fahrenheit f1 = c1;

    cout << "Enter temperature in Fahrenheit: ";
    while (!(cin >> fTemp)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a numeric value for Fahrenheit: ";
    }
    Fahrenheit f2(fTemp);
    Celsius c2 = f2;

    if (c1 == f2)
        cout << "Temperatures are equal\n";
    else
        cout << "Temperatures are not equal\n";

    Fahrenheit fArray[2];
    fArray[0] = f1;
    fArray[1] = Fahrenheit(100.0f);

    for (int i = 0; i < 2; i++) {
        cout << fArray[i].getTemp() << " F\n";
    }

    cout<<"HARSH_HIRPARA_24CE040";
    return 0;
}
