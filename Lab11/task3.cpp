#include <iostream>
#include <exception>

using namespace std;


class TempratureException : public exception {};

template <typename T>

T convertToFahrenheit(T celsius) {
    if (celsius< -273.15)
        throw TempratureException();

    T farenheit = (celsius * 9 / 5) + 32;
    return farenheit;
}


int main() {
    double farenHeit;;
    try {
        farenHeit = convertToFahrenheit(100);
          cout << "Fahrenheit Temp1: " << farenHeit << endl;

         farenHeit = convertToFahrenheit(-300.0);

        cout << "Fahrenheit Temp2: " << farenHeit << endl;

    } 
    catch (const exception& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
