/*
Самое любимое! Будем создавать простую игру, в которой вы будете сражаться с монстрами. Цель игры — собрать максимум золота,
прежде чем вы умрёте или достигнете 20 уровня.
*/

#include <iostream>
#include <string>
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне


	return static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
	 // возвращаем случайное число в заданом диапазоне 
}

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
	struct MonsterData
	{
		const char* name;
		char symbol;
		int health;
		int damage;
		int gold;
	};
	static MonsterData monsterData[MAX_TYPES];
	Monster(Type type)
		: Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, 
			monsterData[type].damage, monsterData[type].gold)	{	}
		static Monster getRandomMonster()
	{
		int num = getRandomNumber(0, MAX_TYPES - 1);
		return Monster(static_cast<Type>(num));
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

bool playAgain()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
	{
		std::cout << "Would you like to play again (y/n)?";
		char answer;
		std::cin >> answer;

		// Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

		std::cin.ignore(32767, '\n'); // удаляем лишний балласт

		// Выполняем проверку пользовательского ввода
		if (answer == 'y')
			return true; // возвращаем обратно в caller
		else if (answer == 'n')
			return false; // возвращаем обратно в caller
		else // в противном случае, сообщаем пользователю что что-то пошло не так
			std::cout << "Oops, that input is invalid.  Please try again.\n";
	}
}

// Этот метод обрабатывает атаку монстра игроком
void attackMonster(Player& p, Monster& m)
{
	// Если игрок мёртв, то он не может атаковать монстра
	if (p.isDead())
		return;

	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

	// Здоровье монстра уменьшается от урона игрока
	m.reduceHealth(p.getDamage());

	// Если монстр мёртв, то увеличиваем level игрока
	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << ".\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}

// Этот метод обрабатывает атаку игрока монстром
void attackPlayer(Monster& m, Player& p)
{
	// Если монстр мёртв, то он не может атаковать игрока
	if (m.isDead())
		return;

	// Здоровье игрока уменьшается от урона монстра
	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

// Этот метод обрабатывает весь бой между игроком и рандомным монстром
void fightMonster(Player& p)
{
	// Сначала генерируем рандомного монстра
	Monster m = Monster::getRandomMonster();
	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

	// Пока монстр или игрок не мёртвы, то бой продолжается
	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input;
		std::cin >> input;
		if (input == 'R' || input == 'r')
		{
			// 50/50 шанс удачного побега
			if (getRandomNumber(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return; // встречу с монстром удалось избежать
			}
			else
			{
				// Неудачная попытка побега даёт монстру право атаковать
				std::cout << "You failed to flee.\n";
				attackPlayer(m, p);
				continue;
			}
		}

		if (input == 'F' || input == 'f')
		{
			// Сначала атакует игрок, затем монстр
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

int main()
{

	std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
	srand(static_cast<int>(mersenne()));  // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
	rand(); // сбрасываем первый результат
	do
	{
		Player p;
		std::cout << "Welcome, " << p.getName() << '\n';

		// Если игрок не мёртв и еще не победил, то игра продолжается
		while (!p.isDead() && !p.hasWon())
			fightMonster(p);

		// К этому моменту игрок либо мёртв, либо победил
		if (p.isDead())
		{
			std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
			std::cout << "Too bad you can't take it with you!\n";
		}
		else
		{
			std::cout << "You won the game with " << p.getGold() << " gold!\n";
		}

		
	} while (playAgain());

	std::cout << "thank you for the game";
	
	return 0;
}
