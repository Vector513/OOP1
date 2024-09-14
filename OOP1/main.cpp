#include "application.h"
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Application app;
	//app.run();
	Array array(0);
	number a = 4;
	array.add(a);
	return 0;
}
