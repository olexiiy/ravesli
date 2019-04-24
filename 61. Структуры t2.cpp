/* Создайте структуру для хранения дробных чисел. Структура должна иметь 2 члена: целочисленный числитель и целочисленный
 знаменатель. Объявите две дробные переменные и получите их значения от пользователя. Напишите функцию multiply() 
(параметрами которой будут эти две переменные), которая будет перемножать эти числа и выводить результат в виде 
десятичного числа.
*/

#include <iostream>

struct Drob
{
	long long verh;
	long long niz;
};

void multiply(Drob drob1, Drob drob2)
{
	using namespace std;
	cout << "total result ";
	cout << static_cast<double>(drob1.verh * drob2.verh) / (drob1.niz * drob2.niz);
	
}


int main()
{
	using namespace std;
	
	std::cout << "The size of Drob  is " << sizeof(Drob) << "\n";

	// D1 
	Drob drob1;
	std::cout << "Input the Verh first drob: \n"; 
	std::cin >> drob1.verh;
	std::cout << "Input the Niz first drob: \n";
	std::cin >> drob1.niz;

	// D2 
	Drob drob2;
	std::cout << "Input the Verh second drob: \n";
	std::cin >> drob2.verh;
	std::cout << "Input the Niz second drob: \n";
	std::cin >> drob2.niz;
	
	multiply(drob1, drob2);

	return 0;

}
