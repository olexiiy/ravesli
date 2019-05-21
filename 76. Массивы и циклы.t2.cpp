/*
Выведите на экран следующий массив с помощью цикла:
    int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
Попросите пользователя ввести число от 1 до 9. Если пользователь введёт что-либо другое — попросите его снова 
ввести число и так до тех пор, пока он не введёт корректное значение из заданного диапазона. Как только пользователь
введёт число от 1 до 9, выведите массив на экран. Затем найдите в массиве элемент с числом, которое ввёл пользователь,
и выведите его индекс.
*/


#include <iostream>

int getNumber()
{
	int sm{};
	do
	{
		std::cout << "Enter a number from 1 to 9 included ";
		std::cin >> sm;


		// Если пользователь ввёл некорректное значение
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

		// Выполняем проверку пользовательского ввода
	} while (sm < 1 || sm > 9);
	return sm;
}

int main()
{
	int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	const int numElements = sizeof(array) / sizeof(array[0]);

	int number = getNumber();

	for (int element = 0; element < numElements; ++element)
		std::cout << "The element number " << element + 1 << " is " << array[element] << '\n';

	for (int element = 0; element < numElements; ++element)
		if (array[element] == number)
		{
			std::cout << "The number " << number << " has index " << element << '\n';
			break;
		}
	delete[] array; // освобождение памяти;

	return 0;
}
