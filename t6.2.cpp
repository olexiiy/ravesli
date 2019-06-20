/*
Создайте структуру, содержащую имя и оценку учащегося (по шкале от 0 до 100). Спросите у пользователя, сколько учеников 
он хочет ввести. Динамически выделите массив для хранения всех студентов. Затем попросите пользователя ввести для 
каждого студента его имя и оценку. Как только пользователь ввёл все имена и оценки, отсортируйте список по убывания 
оценок студентов (сначала самый высокий бал). Затем выведите все имена и оценки в отсортированном виде.

Для следующего ввода:

Andre
74
Max
85
Anton
12
Josh
17
Sasha
90

Вывод должен быть следующим:

Sasha got a grade of 90
Max got a grade of 85
Andre got a grade of 74
Josh got a grade of 17
Anton got a grade of 12

Подсказка: Вы можете изменить алгоритм сортировки массива методом выбора из урока №77 для сортировки вашего 
динамического массива. Если вы напишите сортировку массива отдельной функцией, то массив должен передаваться по 
адресу (как указатель).
*/

#include <iostream>
#include <string>
#include <utility>

struct Student
{
	std::string name{};
	int mark{};
};
int getValue()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
	{
		
		int a;
		std::cin >> a;

		// Проверка на предыдущее извлечение
		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // удаляем лишние значения

			return a;
		}
	}
}
void input(Student *array, int number)
{
	for (int index = 0; index < number; ++index)
	{
		std::cout << "Enter name #" << index + 1 << " ";
		std::cin >> array[index].name;
		std::cout << "Enter a mark: ";
		array[index].mark = getValue();
	}
}
void sortArray(Student *array, int number)
{
	for (int startIndex = 0; startIndex < number - 1; ++startIndex)
	{
		// Перебираем каждый элемент массива до последнего элемента (не включительно)
		// Последний элемент не имеет пары для сравнения
		for (int currentIndex = 0; currentIndex < number - 1; ++currentIndex)
		{
			// Если текущий элемент больше элемента после него, то меняем их местами
			if (array[currentIndex].mark < array[currentIndex + 1].mark)
				// то запоминаем его
				std::swap(array[currentIndex], array[currentIndex + 1]);
		}
	}
}
void output(Student* array, int number)
{
	for (int index{}; index < number; ++index)
	{
		std::cout << array[index].name << " got a grade of " << array[index].mark;
		std::cout << std::endl;
	}
}
int main()
{
	using namespace std;
	cout << "How much students do you have ?  ";
	//вводим количестиво людей в массиве
	int number = getValue();
	//создаем указаное количество массивов
	Student *array = new Student[number];
	//вводим каждоем имя и оценку
	input(array, number);
	// сортируем массив
	sortArray(array, number);
	// Теперь, когда весь массив отсортирован - выводим его на экран
	output(array, number);

	return 0;
}
