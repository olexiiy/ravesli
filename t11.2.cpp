/* 
Создайте классы Apple и Banana, которые наследуют класс Fruit. У класса Fruit есть две переменные-члены: name и color
Добавьте новый класс GrannySmith, который наследует класс Apple.
*/

#include <iostream>
#include <string>
class Fruit
{
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string name, std::string color) : m_name(name), m_color(color) {}
	std::string getName() { return m_name; }
	std::string getColor() { return m_color; }
};

class Apple : public Fruit
{
// Предыдущий конструктор, который мы использовали для Apple, имел фиксированное имя ("apple")
// Нам нужен новый конструктор для GrannySmith, чтобы иметь возможность задавать имя для фрукта
protected:
	Apple(std::string name, std::string color)
		: Fruit(name, color)
	{
	}
public:
	Apple(std::string color = "red") : Fruit("apple", color) {}

};

class Banana : public Fruit
{
	public:
	Banana () : Fruit("banana", "yellow"){}
};

class GrannySmith : public Apple
{
public:

	GrannySmith() : Apple("Granny Smith apple", "green") {}
	
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
