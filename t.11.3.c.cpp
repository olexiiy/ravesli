#include <iostream>
#include <string>
#include <ostream>

std::string enterName()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
	{
		std::cout << "Enter your name:  ";
		std::string a;
		std::getline(std::cin, a);
				// Проверка на предыдущее извлечение
		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{	std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			std::cout << "Oops, that input is invalid.  Please try again.\n";		}
		else
		{
			return a;
		}	}	}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
public:
	Creature(std::string name, char symbol, int health, int damage, int gold)
	: m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)	{}
	const std::string& getName() { return m_name; }
	char getSymbol()  { return m_symbol; }
	int getHealth()  { return m_health; }
	int getDamage() { return m_damage; }
	int getGold()  { return m_gold; }
	
	void reduceHealth(int reduceHealth) { m_health -= reduceHealth; }
	bool isDead() { return m_health <= 0; }
	void addGold(int addGold) { m_gold += addGold; }
	
};

class Player : public Creature
{
private:
	int m_level = 1;
public:
	 Player () : Creature(enterName(), '@', 10, 1 , 0) {}
	 void levelUp() { ++m_level; ++m_damage; }
	 int getLevel() { return m_level; }
	 bool hasWon() { return  m_level >= 20; }
};

enum Type
{
	DRAGON, ORC, SLIME, MAX_TYPES	
};

class Monster : public Creature
{
public:
	enum Type
	{	DRAGON, ORC, SLIME, MAX_TYPES	};

};

int main()
{
	Creature o("orc", 'o', 4, 2, 10);
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold." << std::endl;

	Player p;
	std::cout << "Welcome, " << p.getName() << ".\n";

	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.";
	
	return 0;
}
