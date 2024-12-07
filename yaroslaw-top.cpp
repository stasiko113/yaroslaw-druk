#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 12;
    int A[MAX_SIZE] = { 0 };
    int n = 0;
    bool is_data_entered = false;
    int choice;

    cout << "\nДан массив A(n), n<12, целого типа. \n";
    cout << "Получить вектор M, расположив в нем вначале все элементы массива A, \n";
    cout << "кратные минимальному элементу массива A, затем – все остальные.  \n";

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Установить количество элементов массива\n";
        cout << "2. Ввод данных\n";
        cout << "3. Случайный ввод данных\n";
        cout << "4. Вывод данных\n";
        cout << "5. Формирование и сортировка массива\n";
        cout << "6. Выход\n";
        cout << "Выберите действие: ";

        cin >> choice;

        if (choice == 1) {
            cout << "Введите количество элементов массива (n <= 12): ";
            cin >> n;
            if (n < 1 || n > MAX_SIZE) {
                cout << "Некорректное количество элементов. Пожалуйста, введите значение от 1 до 12." << endl;
                n = 0;
            }
            else {
                is_data_entered = true;
            }
        }
        else if (choice == 2) {
            if (n == 0) {
                cout << "Сначала установите количество элементов массива." << endl;
                continue;
            }
            cout << "Введите элементы массива: ";
            for (int i = 0; i < n; i++) {
                cin >> A[i];
            }
            is_data_entered = true;
        }
        else if (choice == 3) {
            if (n == 0) {
                cout << "Сначала установите количество элементов массива." << endl;
                continue;
            }
            srand(static_cast<unsigned>(time(0)));
            cout << "Случайно сгенерированные элементы массива: ";
            for (int i = 0; i < n; i++) {
                A[i] = rand() % 100;
                cout << A[i] << " ";
            }
            cout << endl;
            is_data_entered = true;
        }
        else if (choice == 4) {
            if (is_data_entered) {
                cout << "Массив A: ";
                for (int i = 0; i < n; i++) {
                    cout << A[i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "Данные не введены." << endl;
            }
        }
        else if (choice == 5) {
            if (is_data_entered) {
                int min_elem = A[0];
                for (int i = 1; i < n; i++) {
                    if (A[i] < min_elem) {
                        min_elem = A[i];
                    }
                }
                if (min_elem == 0) {
                    cout << "Ошибка: минимальный элемент массива равен 0. Деление невозможно." << endl;
                }
                else {
                    vector<int> M;

                    for (int i = 0; i < n; i++) {
                        if (A[i] % min_elem == 0) {
                            M.push_back(A[i]);
                        }
                    }

                    for (int i = 0; i < n; i++) {
                        if (A[i] % min_elem != 0) {
                            M.push_back(A[i]);
                        }
                    }

                    if (!M.empty()) {
                        cout << "Сформированный массив M до сортировки: ";
                        for (int elem : M) {
                            cout << elem << " ";
                        }
                        cout << endl;
                        sort(M.begin(), M.end());
                        cout << "Сформированный массив M после сортировки: ";
                        for (int elem : M) {
                            cout << elem << " ";
                        }
                        cout << endl;
                    }
                }
            }
            else {
                cout << "Данные не введены." << endl;
            }
        }
        else if (choice == 6) {
            return 0;
        }
        else {
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}