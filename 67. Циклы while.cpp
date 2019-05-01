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
