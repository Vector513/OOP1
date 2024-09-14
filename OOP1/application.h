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
        char commands[] = "1) Ввести значения массива с консоли\n2) Рассчитать среднее и СКО элементов массива\n3) Отсортировать элементы массива по возрастанию или убыванию\n4) Изменить размерность массива\n5) Изменить значение элемента массива\ns) Вывести текущие элементы массива\nc) Вывести список команд\ne) Выход из программы\n";

        char command = 'c';

        do {
            if (command == 'e') {
                cout << "Программа была завершена по воле пользователя\n";
                break;
            }

            else if (command == 'c') {
                cout << commands;
            }

            else if (command == 's') {
                array.show(cout);
            }

            else if (command == '1') {
                array.clear();
                fill();
                cout << "Массив был успешно заполнен введёнными значениями\n";
            }
            else if (command == '2') {
                cout << "Среднее значение: " << (array.average()) << '\n';
                cout << "СКО: " << (array.MSD()) << '\n';
            }
            else if (command == '3') {
                cout << "Отсортировать по возрастанию? (y/n): ";
                char isIncreased = ' ';
                cin >> isIncreased;
                if (isIncreased == 'y') {
                    array.sort();
                    cout << "Элементы массива были успешно отсортированы по возрастанию\n";
                    array.show(cout);
                }
                else if (isIncreased == 'n') {
                    array.sort(true);
                    cout << "Элементы массива были успешно отсортированы по убыванию\n";
                    array.show(cout);
                }
                else {
                    cout << "Вы ввели неправильный символ, массив не был отсортирован\n";
                }
            }
            else if (command == '4') {
                cout << "Введите новую размерность текущего массива: ";
                int newCapacity;
                cin >> newCapacity;
                resize(newCapacity);
                cout << "Размер массива был успешно изменён на " << newCapacity << '\n';
            }
            else if (command == '5') {
                cout << "Введите индекс и новое значение элемента массива: ";
                int index = 0;
                number value = 0.0;
                cin >> index >> value;
                array[index] = value;
                cout << "Значение элемента массива с индексом " << index << " было успешно изменено\n";
                array.show(cout);
            }

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 71 38 11 28 20 42 39 89 48 30 35 40 71 97 8 2 2 72 34 38
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

    void resize(int newCapacity) 
    {
        array.resize(newCapacity);
    }
    
};