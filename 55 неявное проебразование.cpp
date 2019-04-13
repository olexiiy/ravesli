include <iostream>
#include <typeinfo> // для typeid()

int main()
{
	short x(3);
	short y(6);
	std::cout << typeid(x + y).name() << " " << x + y << std::endl; // узнаем решающий тип данных в выражении x + y
	double a(3.0);
	short b(2);
	std::cout << typeid(a + b).name() << " " << a + b << std::endl; // узнаем решающий тип данных в выражении a + b
	std::cout << 5u - 10;
	return 0;
} // внешняя переменная уничтожается
