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
        char commands[] = "1) ������ �������� ������� � �������\n2) ���������� ������� � ��� ��������� �������\n3) ������������� �������� ������� �� ����������� ��� ��������\n4) �������� ����������� �������\n5) �������� �������� �������� �������\ns) ������� ������� �������� �������\nc) ������� ������ ������\ne) ����� �� ���������\n";

        char command = 'c';

        do {
            if (command == 'e') {
                cout << "��������� ���� ��������� �� ���� ������������\n";
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
                cout << "������ ��� ������� �������� ��������� ����������\n";
            }
            else if (command == '2') {
                cout << "������� ��������: " << (array.average()) << '\n';
                cout << "���: " << (array.MSD()) << '\n';
            }
            else if (command == '3') {
                cout << "������������� �� �����������? (y/n): ";
                char isIncreased = ' ';
                cin >> isIncreased;
                if (isIncreased == 'y') {
                    array.sort();
                    cout << "�������� ������� ���� ������� ������������� �� �����������\n";
                    array.show(cout);
                }
                else if (isIncreased == 'n') {
                    array.sort(true);
                    cout << "�������� ������� ���� ������� ������������� �� ��������\n";
                    array.show(cout);
                }
                else {
                    cout << "�� ����� ������������ ������, ������ �� ��� ������������\n";
                }
            }
            else if (command == '4') {
                cout << "������� ����� ����������� �������� �������: ";
                int newCapacity;
                cin >> newCapacity;
                resize(newCapacity);
                cout << "������ ������� ��� ������� ������ �� " << newCapacity << '\n';
            }
            else if (command == '5') {
                cout << "������� ������ � ����� �������� �������� �������: ";
                int index = 0;
                number value = 0.0;
                cin >> index >> value;
                array[index] = value;
                cout << "�������� �������� ������� � �������� " << index << " ���� ������� ��������\n";
                array.show(cout);
            }

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 71 38 11 28 20 42 39 89 48 30 35 40 71 97 8 2 2 72 34 38
            cout << separator << '\n';
            cout << "������� ��������: ";
            cin >> command;
            cout << '\n';

        } while (true);
    }

    void fill() 
    {
        string input;
        cout << "������� �������� ������: ";
        cin.get();
        getline(cin, input);
        array.fill(input);
    }

    void resize(int newCapacity) 
    {
        array.resize(newCapacity);
    }
    
};