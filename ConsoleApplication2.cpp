#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <Windows.h>

using namespace std;

class Calculator {
private:
    string aston;
    vector<int> numbers;
    vector<int> values;
    vector<char> variables;
    int result = 0;
    char lo = '+';

public:
    Calculator(string a) {
        this->aston = a;
    }

    void Calce(char variable, int value) {
        auto it = find(variables.begin(), variables.begin() + variables.size(), variable);
        if (it != variables.begin() + variables.size()) {
            int index = distance(variables.begin(), it);
            values[index] = value;
        }
        else {
            cout << "Ошибка: Значение переменной " << variable << " не задано." << endl;
        }
    }

    int Calca() {
        int len = aston.length();
        auto Reshenie = [this](int calcu, char op) {
            switch (op) {
            case '+':
                return result + calcu;
            case '-':
                return result - calcu;
            case '*':
                return result * calcu;
            case '/':
                return result / calcu;
            default:
                cout << "Ошибка: " << op << endl;
                break;
            }
            return result;
        };
        for (int i = 0; i < len; ++i) {
            char cifra = aston[i];

            if ((cifra >= 'a' && cifra <= 'z') || (cifra >= 'A' && cifra <= 'Z')) {
                auto it = find(variables.begin(), variables.begin() + variables.size(), cifra);
                if (it != variables.begin() + variables.size()) {
                    int index = distance(variables.begin(), it);
                    numbers.push_back(values[index]);
                }
                else {
                    cout << "Ошибка: Значение переменной " << cifra << " не задано." << endl;
                    return result;
                }
            }
            else if (cifra == '0' || cifra == '1' || cifra == '2' || cifra == '3' || cifra == '4' || cifra == '5' || cifra == '6' || cifra == '7' || cifra == '8' || cifra == '9') {
                int Calcule = cifra;


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
    cout << "Введите математическое выражение: ";
    cin >> aston;

    Calculator calc(aston);

    for (int i = 0; i < aston.length(); ++i) {
        char var = aston[i];
        if ((var >= 'a' && var <= 'z') || (var >= 'A' && var <= 'Z')) {
            int value;
            cout << "Введите значение для переменной " << var << ": ";
            cin >> value;
            calc.Calce(var, value);
        }
    }

    int result = calc.Calca();

    cout << "Результат вычислений: " << result << endl;

    return 0;
}