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
        char commands[] = "1) ������ �������� ������� � �������\n2) ���������� ������� � ��� ��������� �������\n3) ������������� �������� ������� �� ����������� ��� ��������\n4) �������� ����������� �������\n5) �������� �������� �������� �������\ns) ������� ������� �������� �������";

        char command = 'c';

        do {
            if (command == 'e') {
                cout << "��������� ���� ��������� �� ���� ������������";
                break;
            }

            else if (command == 'c') {
                cout << commands;
            }

            else if (command == '1') {
                cout << commands;
            }

            cout << separator << '\n';
            cout << "������� ��������: ";
            cin >> command;
            cout << '\n';

        } while (true);
    }

};