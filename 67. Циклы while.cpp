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

/*
Теперь сделайте так, чтобы цифры выводились следующим образом (используя программу из предыдущего задания):

        1
      2 1
    3 2 1
  4 3 2 1
5 4 3 2 1

Подсказка: Разберитесь сначала, как вывести числа следующим образом:

X X X X 1
X X X 2 1
X X 3 2 1
X 4 3 2 1
5 4 3 2 1


*/

int main()
{
	int outer = 1;
	while (outer <= 5)
	{
		int inner = 5;
		while (inner >= 1)
		{
			// Первое число в любом ряде совпадает с номером этого ряда
			// Поэтому числа должны выводиться только если <= номера ряда, в противном случае, выводится пробел
			if (inner <= outer)
				std::cout << inner << " ";
			else
				std::cout << "  "; // вставляем дополнительные пробелы
			--inner;
		}

		// Вставляем символ новой строки в конце каждого рядка
		std::cout << "\n";
		++outer;
	}

	return 0;
}

/*
Ромб из чисел
*/




int main()
{
	int outer = 1;
	while (outer <= 9)
	{
		int inner = 9;                                          // 0
		while (inner >= 1)									   // 1 0
		{
			inner--;                                         // 2 1 0
			if (inner >= outer)                          // 3 2 1 0
				std::cout << ' ';                         // 4 3 2 1 0
			else  std::cout << inner << " ";
		}// 5 4 3 2 1 0
		std::cout << "\n";                       // 6 5 4 3 2 1 0
		++outer;                                  // 7 6 5 4 3 2 1 0
	}                                                 // 8 7 6 5 4 3 2 1 0
	int auter = 8;                             // 8 7 6 5 4 3 2 1 0
	while (auter >= 1)                       // 7 6 5 4 3 2 1 0
	{                                                   // 6 5 4 3 2 1 0
		int enner = 9;                            // 5 4 3 2 1 0
		while (enner >= 1)                      // 4 3 2 1 0
		{
			enner--;                                 // 3 2 1 0
			if (enner >= auter)                      // 2 1 0
				std::cout << ' ';                         // 1 0
			else  std::cout << enner << " ";
		}  // 0
		std::cout << "\n";
		--auter;
	}
	return 0;
}
