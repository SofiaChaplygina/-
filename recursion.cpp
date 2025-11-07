#include <iostream>
using namespace std;

double power(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / power(x, -n);
    
    double half = power(x * x, n / 2);
    if (n % 2 == 0)
        return half;
    else
        return x * half;
}

int main() {
    double base;
    int exponent;
    
    cout << "Введите основание: ";
    cin >> base;
    
    cout << "Введите показатель степени: ";
    cin >> exponent;
    
    double result = power(base, exponent);
    
    cout << base << " в степени " << exponent << " = " << result << endl;
    
    return 0;
}
//Введите основание: 4
//Введите показате�ь степени: 3
//4 в степени 3 = 64
