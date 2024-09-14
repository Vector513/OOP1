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
        char commands[] = "1) ������ �������� ������� � �������\n2) ���������� ������� � ��� ��������� �������\n3) ������������� �������� ������� �� ����������� ��� ��������\n4) �������� ����������� �������\n5) �������� �������� �������� �������\ns) ������� ������� �������� �������\n\nc) ������� ������ ������\ne) ����� �� ���������\n";

        char command = 'c';

        do {
            if (command == 'e') {
                cout << "��������� ���� ��������� �� ���� ������������";
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
                cout << "������� ����� ����������� �������� �������: ";
                int newCapacity;
                cin >> newCapacity;
                resize(newCapacity);
                cout << "������ ������� ��� ������� ������ �� " << newCapacity;
            }
            else if (command == '5') {
                cout << commands;
            }


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

    void resize(int newCapacity) {
        array.resize(newCapacity);
    }
    
};