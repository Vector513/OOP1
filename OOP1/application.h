#pragma once
#include "array.h"
#include <iostream>

using namespace std;


class Application
{
private:
public:
    void run()
    {
        char separator[] = "------------------------------------------------------------------------------------------------------------------------";
        char commands[] = "1) Ввести значения массива с консоли\n2) Рассчитать среднее и СКО элементов массива\n3) Отсортировать элементы массива по возрастанию или убыванию\n4) Изменить размерность массива\n5) Изменить значение элемента массива\ns) Вывести текущие элементы массива";

        char command = 'c';

        do {
            if (command == 'e') {
                cout << "Программа была завершена по воле пользователя";
                break;
            }

            else if (command == 'c') {
                cout << commands;
            }

            else if (command == '1') {
                cout << commands;
            }

            cout << separator << '\n';
            cout << "Введите комманду: ";
            cin >> command;
            cout << '\n';

        } while (true);
    }

};