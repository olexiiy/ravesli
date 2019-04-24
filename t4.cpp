#include <iostream>
#include <string>

using Word = std::string;

// создаем класс перечесления Monster  
enum class MonsterTypes
{
	MONSTER_OGRE,
	MONSTER_GOBLIN,
	MONSTER_SKELETON,
	MONSTER_ORC,
	MONSTER_TROLL
};

 // создаем структуру с перечеслением Monster  

struct PresentMonster
{
	MonsterTypes    type;
	std::string      name;
	int			    health;
};

void printMonster(MonsterTypes type)
{
	using namespace std;

	cout << "This ";
	if (type == MonsterTypes::MONSTER_OGRE)
		std::cout << "OGRE";
	else if (type == MonsterTypes::MONSTER_GOBLIN)
		std::cout << "GOBLIN";
	else if (type == MonsterTypes::MONSTER_SKELETON)
		std::cout << "SKELETON";
	else if (type == MonsterTypes::MONSTER_ORC)
		std::cout << "ORC";
	else if (type == MonsterTypes::MONSTER_TROLL)
		std::cout << "TROLL";
	else
		std::cout << "Who knows!";

	
}

Word getName()	// Вводим имя монстра
{
	std::string nameUser;
	std::getline(std::cin, nameUser);
	std::cin.ignore(32767, '\n');
	return nameUser;
}


int main()
{
	using namespace std;
	PresentMonster goblin;
	cout << "input the monster type ";
	int inputType;
	std::cin >> inputType;
	goblin.type = static_cast<MonsterTypes>(inputType);
	
	goblin.name = getName();
	
	std::cin >> goblin.health;
	printMonster(goblin.type);
	std::cout << " is named " << (goblin.name) << "and has " << goblin.health << " health";
	
	


	return 0;

}
