#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h>

using namespace std;

class Calculator {
private:
    string aston;
    int vishka;
    vector<int> numbers;

public:
    Calculator(string a) {
        this->aston = a;
        this->vishka = 0;
    }

    void Calce(int value) {
        this->vishka = value;
    }
    int Calca() {
        int len = aston.length();
        int result = 0;
        char lo = '+';
        auto Reshenie = [](int calcu, char op) {
            int result = 0;
            switch (op) {
            case '+': result += calcu; break;
            case '-': result -= calcu; break;
            case '*': result *= calcu; break;
            case '/': result /= calcu; break;
            else if{
                cout << "Ошибка: " << op << endl;
                break;
                }
            }
            return result;
        };

        for (int i = 0; i < len; ++i) {
            char cifra = aston[i];

            if (cifra == 'x') {
                if (numbers.size() == 0) { 
                    numbers.push_back(1);
                }
                numbers[numbers.size() - 1] *= vishka;
            }
            else if (cifra == '0' || cifra == '1' || cifra == '2' || cifra == '3' || cifra == '4' || cifra == '5' || cifra == '6' || cifra == '7' || cifra == '8' || cifra == '9') {
                int Calcule = cifra - '0';
               
                while (i + 1 < len) {
                    char nextCifra = aston[i + 1];
                    if (nextCifra == '0' || nextCifra == '1' || nextCifra == '2' || nextCifra == '3' || nextCifra == '4' || nextCifra == '5' || nextCifra == '6' || nextCifra == '7' || nextCifra == '8' || nextCifra == '9') {
                        Calcule = Calcule * 10 + nextCifra;
                        ++i;
                    }
                    else {
                        break; 
                    }
                }

                numbers.push_back(Calcule);
            }
            else if (cifra == '+' || cifra == '-' || cifra == '*' || cifra == '/') {
                int calcu = numbers[numbers.size() - 1];  
                result = Reshenie(calcu, lo);
                lo = cifra;
            }
        }

        if (numbers.size() > 0) {
            int calcu = numbers[numbers.size() - 1];
            result = Reshenie(calcu, lo);
        }

        return result;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string aston;
    cout << "Введіть математичний вираз (тільки зі змінною x): ";
    cin >> aston;

    Calculator calc(aston);

    int value;
    cout << "Введіть значення змінної x: ";
    cin >> value;

    calc.Calce(value);

    int result = calc.Calca();

    cout << "Результат обчислення: " << result << endl;

    return 0;
}