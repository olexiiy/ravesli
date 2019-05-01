/*
Определите перечисление (или класс enum) Animal, которое содержит следующих животных: 
pig, chicken, goat, cat, dog и ostrich. Напишите функцию getAnimalName(), которая принимает параметр Animal 
и использует switch для возврата типа животного в качестве строки. Напишите ещё одну функцию — printNumberOfLegs()
, которая использует switch для вывода количества лапок соответствующего типа животных. Убедитесь, что обе функции 
имеют кейс default, который выводит сообщение об ошибке. Вызовите printNumberOfLegs() в main(), используя в качестве 
параметров cat и chicken.

Примерный результат выполнения вашей программы:

A cat has 4 legs.
A chicken has 2 legs.
*/

#include <iostream>
#include <string>

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	ostrich
};

std::string getAnimalName(Animal possible)
{
	switch (possible)
	{
	case Animal::pig:
	{
		return "pig";
		break;
	}
	case Animal::chicken:
	{
		return "chicken";
		break;
	}
	case Animal::goat:
	{
		return "goat";
		break;
	}
	case Animal::cat:
	{
		return "cat";
		break;
	}

	case Animal::dog:
	{
		return "dog";
		break;
	}

	case Animal::ostrich:
	{
		return "ostrich";
		break;
	}

	default:
		return "other animal";
		break;
	}
}

int getNumberOfLegs(Animal legs)
{

	
	switch (legs)
	{


	case Animal::pig:
	case Animal::goat:
	case Animal::dog:
	case Animal::cat:
	{
		return 4;
		break;
	}


	case Animal::chicken:
	case Animal::ostrich:
	{
		return 2;
		break;
	}

	default:
		return 0;
		break;
	}
}

void printNumberOfLegs(Animal type)
{
	using namespace std;
	cout << "A " << getAnimalName(type) << " has " << getNumberOfLegs(type) << " legs." << endl;
}

int main()
{

	printNumberOfLegs(Animal::cat);
	printNumberOfLegs(Animal::chicken);
	system("pause");
	return 0;
}
