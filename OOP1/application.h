#pragma once
#include "array.h"

class Application
{
private:
    Array array;
public:
    void run()
    {
        char separator[] = "------------------------------------------------------------------------------------------------------------------------";
        char commands[] = "1) Ввести значения массива с консоли\n2) Рассчитать среднее и СКО элементов массива\n3) Отсортировать элементы массива по возрастанию или убыванию\n4) Изменить размерность массива\n5) Изменить значение элемента массива\ns) Вывести текущие элементы массива\n\nc) Вывести список команд\ne) Выход из программы\n";

        char command = 'c';

        do {
            if (command == 'e') {
                cout << "Программа была завершена по воле пользователя";
                break;
            }

            else if (command == 'c') {
                cout << commands;
            }

            else if (command == 's') {
                array.show();
            }

            else if (command == '1') {
                fill();
            }
            else if (command == '2') {
                cout << commands;
            }
            else if (command == '3') {
                cout << commands;
            }
            else if (command == '4') {
                cout << "Введите новую размерность текущего массива: ";
                int newCapacity;
                cin >> newCapacity;
                resize(newCapacity);
                cout << "Размер массива был успешно изменён на " << newCapacity;
            }
            else if (command == '5') {
                cout << commands;
            }


            cout << separator << '\n';
            cout << "Введите комманду: ";
            cin >> command;
            cout << '\n';

        } while (true);
    }

    void fill() 
    {
        string input;
        cout << "Введите элементы списка: ";
        cin.get();
        getline(cin, input);
        array.fill(input);
    }

    void resize(int newCapacity) {
        array.resize(newCapacity);
    }
    
};