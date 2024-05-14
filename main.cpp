#include <iostream>
#include <clocale>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>  // Для system()

using namespace std;

class Eq1 {
public:
    void showAnswer() {
        cout << "Уравнение верно при любом x" << endl;
    }
};

class Eq2 {
public:
    void showAnswer() {
        cout << "Уравнение имеет единственный корень x, равный 0" << endl;
    }
};

class Eq3 {
public:
    void showAnswer() {
        cout << "Уравнение не имеет корней" << endl;
    }
};

class Eq4 {
public:
    double x1, x2;
    bool areComplex;

    Eq4(double a, double b, double c) : areComplex(false) {
        double temp = static_cast<double>(c) / a;
        if (temp < 0) {
            areComplex = true;
        } else {
            x1 = sqrt(temp);
            x2 = -sqrt(temp);
        }
    }

    void showAnswer() {
        if (areComplex) {
            cout << "Уравнение имеет комплексные корни." << endl;
        } else {
            cout << "Данное квадратное уравнение имеет 2 корня:" << endl;
            cout << "Первый корень: " << x1 << endl;
            cout << "Второй корень: " << x2 << endl;
        }
    }
};

class Eq5 {
public:
    double x1;

    Eq5(double b, double c) {
        x1 = (c / b);
    }

    void showAnswer() {
        cout << "Данное квадратное уравнение имеет один единственный корень:" << x1 << endl;
    }
};

class Eq6 {
public:
    double disc, x1, x2;
    bool isComplex;

    Eq6(double a, double b, double c) : isComplex(false) {
        disc = b * b - 4 * a * c;
        if (disc > 0) {
            x1 = (-b + sqrt(disc)) / (2 * a);
            x2 = (-b - sqrt(disc)) / (2 * a);
        }
        else if (disc == 0) {
            x1 = x2 = -b / (2 * a);
        }
        else {
            isComplex = true;
            x1 = -b / (2 * a);
            x2 = sqrt(-disc) / (2 * a);
        }
    }

    void showAnswer() {
        if (isComplex) {
            cout << "Данное квадратное уравнение имеет комплексные корни:" << endl;
            cout << "x1 = " << x1 << " + " << x2 << "i" << endl;
            cout << "x2 = " << x1 << " - " << x2 << "i" << endl;
        }
        else if (disc >= 0) {
            cout << "Данное квадратное уравнение имеет следующие корни:" << endl;
            cout << "Первый корень: " << x1 << endl;
            cout << "Второй корень: " << x2 << endl;
        }
    }
};

class Eq7 {
public:
    void showAnswer() {
        cout << "Данное квадратное уравнение имеет одно единственное решение при x = 0" << endl;
    }
};

class Eq8 {
public:
    double x1 = 0;
    double x2;

    Eq8(double a, double b) {
        x2 = -b / a;
    }

    void showAnswer() {
        cout << "Данное квадратное уравнение имеет два корня:" << endl;
        cout << "Первый равен:" << x1 << endl;
        cout << "Второй равен:" << x2 << endl;
    }
};

bool inputCoefficient(double &coeff) {
    string input;
    do {
        getline(cin, input);
        replace(input.begin(), input.end(), ',', '.');
        char* p;
        coeff = strtod(input.c_str(), &p);
        if (*p != 0 || (input.find('.') != string::npos && input.find_first_of('.') != input.find_last_of('.'))) {
            cout << "Неверный ввод" << endl;
        } else {
            return true;
        }
    } while (true);
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool isValidMainMenuChoice(const string &choice) {
    return choice == "1" || choice == "2" || choice == "3";
}

bool isValidPostSolutionChoice(const string &choice) {
    return choice == "1" || choice == "2";
}

void displayMainMenu() {
    clearScreen();  // Очистить экран перед отображением главного меню
    cout << "----------------------------------------" << endl;
    cout << "|          Решатель квадратных         |" << endl;
    cout << "|            уравнений                 |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "|   Выберите действие:                 |" << endl;
    cout << "|   1. Решить квадратное уравнение     |" << endl;
    cout << "|   2. Посмотреть инструкцию           |" << endl;
    cout << "|   3. Завершить программу             |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Выберите действие: ";
}

void displayPostSolutionMenu() {
    cout << "----------------------------------------" << endl;
    cout << "| Хотите решить еще одно уравнение?    |" << endl;
    cout << "| 1. Решить еще одно уравнение         |" << endl;
    cout << "| 2. Вернуться в начальное меню        |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Выберите опцию: ";
}

void programLogic() {
    clearScreen();
    double a, b, c;
    cout << "Введите коэффициенты для уравнения A, B и C:" << endl;
    cout << "Коэффициент A: ";
    inputCoefficient(a);
    cout << "Коэффициент B: ";
    inputCoefficient(b);
    cout << "Коэффициент C: ";
    inputCoefficient(c);

    // Решение уравнения в зависимости от коэффициентов
    if (a == 0 && b == 0 && c == 0) {
        Eq1 eq1; eq1.showAnswer();
    } else if (a != 0 && b == 0 && c == 0) {
        Eq2 eq2; eq2.showAnswer();
    } else if (a == 0 && b == 0 && c != 0) {
        Eq3 eq3; eq3.showAnswer();
    } else if (a != 0 && b == 0 && c != 0) {
        Eq4 eq4(a, b, c); eq4.showAnswer();
    } else if (a == 0 && b != 0 && c != 0) {
        Eq5 eq5(b, c); eq5.showAnswer();
    } else if (a != 0 && b != 0 && c != 0) {
        Eq6 eq6(a, b, c); eq6.showAnswer();
    } else if (a == 0 && b != 0 && c == 0) {
        Eq7 eq7; eq7.showAnswer();
    } else {
        Eq8 eq8(a, b); eq8.showAnswer();
    }
}

void manual() {
    clearScreen();
    cout << "----------------------------------------" << endl;
    cout << "|    Инструкция по использованию        |" << endl;
    cout << "|      программы для решения           |" << endl;
    cout << "|        квадратных уравнений          |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Выбор действия:" << endl;
    cout << "   - Главное меню предлагает три действия:" << endl;
    cout << "     1. Решить квадратное уравнение." << endl;
    cout << "     2. Посмотреть инструкцию." << endl;
    cout << "     3. Завершить программу." << endl;
    cout << endl;
    cout << "2. Решение квадратного уравнения:" << endl;
    cout << "   - Выберите действие \"Решить квадратное уравнение\" (введите '1')." << endl;
    cout << "   - Введите значения коэффициентов A, B и C для уравнения Ax^2 + Bx + C = 0." << endl;
    cout << "   - Используйте точку в качестве разделителя для десятичных чисел." << endl;
    cout << "   - После ввода коэффициентов программа выведет корни уравнения, если они существуют." << endl;
    cout << endl;
    cout << "3. Просмотр инструкции:" << endl;
    cout << "   - Выберите действие \"Посмотреть инструкцию\" (введите '2')." << endl;
    cout << "   - Инструкция по использованию программы будет отображена на экране." << endl;
    cout << "   - Нажмите Enter, чтобы вернуться в главное меню." << endl;
    cout << endl;
    cout << "4. Завершение программы:" << endl;
    cout << "   - Если вы хотите завершить программу, выберите действие \"Завершить программу\" (введите '3')." << endl;
    cout << endl;
    cout << "5. Ошибки ввода:" << endl;
    cout << "   - При некорректном вводе программа сообщит об ошибке и попросит ввести данные заново." << endl;
    cout << endl;
    cout << "6. Дополнительно:" << endl;
    cout << "   - После решения уравнения вы можете выбрать, хотите ли вы решить еще одно уравнение или вернуться в главное меню." << endl;
    cout << "   - Программа также предоставляет возможность просмотра истории решенных уравнений." << endl;
    cout << endl;
    cout << "7. Повторный запуск:" << endl;
    cout << "   - После завершения программы вы можете запустить ее снова, чтобы решить другие уравнения или просмотреть историю." << endl;
    cout << "----------------------------------------" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string option;

    do {
        displayMainMenu();
        getline(cin, option);

        while (!isValidMainMenuChoice(option)) {
            cout << "Введено неверное значение или пустой ввод. Пожалуйста, введите 1, 2 или 3." << endl;
            getline(cin, option);
        }

        if (option == "1") {
            do {
                programLogic();
                displayPostSolutionMenu();
                getline(cin, option);
                while (!isValidPostSolutionChoice(option)) {
                    cout << "Введено неверное значение или пустой ввод. Пожалуйста, введите 1 или 2." << endl;
                    getline(cin, option);
                }
            } while (option != "2");
        } else if (option == "2") {
            manual();
            cout << "Нажмите Enter или введите любое значение, чтобы вернуться в меню.";
            cin.get();
        } else if (option == "3") {
            cout << "Завершение программы." << endl;
            return 0;
        }
    } while (true);

    return 0;
}
