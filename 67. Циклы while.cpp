/*Напишите программу, которая выводит буквы английского алфавита от a до z вместе с кодами из таблицы ASCII.

Подсказка: Чтобы выводить символы как целые числа — используйте оператор static_cast.
*/

#include <iostream>

int main()
{
	char count = 'a';
	while (count <= 'z')
	{
		std::cout << count << " " << static_cast<int>(count) << " ";

		++count;
	}
	std::cout << "done!";

	return 0;
}

/*
Инвертируйте программу с последнего подзаголовка «Вложенные циклы» так, чтобы она выводила следующее:

5 4 3 2 1
4 3 2 1
3 2 1
2 1
1

*/

int main()
{
	int outer = 5;
	while (outer >= 1)
	{
		int inner = outer;
		while (inner >= 1)
			std::cout << inner-- << " ";

		// Вставляем символ новой строки в конце каждого рядка
		std::cout << "\n";
		--outer;
	}

	return 0;
}
