/*
Напишите функцию calculate(), которая принимает две переменные типа int и одну переменную типа char, 
которая представляет одну из следующих математических операций: +, -, *, / или % (остаток от числа).
Используйте switch для выполнения соответствующей математической операции над целыми числами и возвратите
результат. Если в функцию передаётся недействительный математический оператор, то функция должна выводить 
ошибку. С оператором деления выполняйте целочисленное деление.
*/

#include <iostream>

void calculate(int x, int y, char op)
{
	using namespace std;
	switch (op) {
	case '+':
	{
		cout << x << " " << op << " " << y << " = " << x + y << endl;
		break;
	}
	case '-':
	{
		cout << x << " " << op << " " << y << " = " << x - y << endl;
		break;
	}
	case '*':
	{
		cout << x << " " << op << " " << y << " = " << x * y << endl;
		break;
	}
	case '/':
	{
		cout << x << " " << op << " " << y << " = " << x / y << endl;
		break;
	}
	case '%':
	{
		cout << x << " " << op << " " << y << " = " << x % y << endl;
		break;
	}
	default:
		cout << "Wrong input" << endl;
		break;
	}

}

int getNumber()
{
	using namespace std;
	cout << "input the number" << endl;
	int x;
	cin >> x;
	return x;
}

int main()
{
	using namespace std;
	int x = getNumber();
	int y = getNumber();
	cout << "input the action" << endl;
	char op{};
	cin >> op;
	calculate(x, y, op);
	system("pause");
	return 0;
}
