
#include <iostream>
#include <string>

enum ItemType // ItemType - это перечисляемый тип, который мы объявили выше
{
	ITEMTYPE_GUN,
	ITEMTYPE_ARBALET,
	ITEMTYPE_SWORD
};

std::string getItemName(ItemType itemType) //itemType (с маленькой i) - это имя переменной, которую мы определили (типа ItemType)
{
	if (itemType == ITEMTYPE_GUN)
		return std::string("Gun");
	if (itemType == ITEMTYPE_ARBALET)
		return std::string("Arbalet");
	if (itemType == ITEMTYPE_SWORD)
		return std::string("Sword");
}

enum Colours
{
	COLOR_PURPLE, // присвоено 0
	COLOR_GRAY, // присвоено 1
	COLOR_BLUE, // присвоено 2
	COLOR_GREEN, // присвоено 3
	COLOR_BROWN, // присвоено 4
	COLOR_PINK, // присвоено 5
	COLOR_YELLOW, // присвоено 6
	COLOR_MAGENTA // присвоено 7
};

void printColor(Colours color)
{
	if (color == COLOR_PURPLE)
		std::cout << "Purple";
	else if (color == COLOR_GRAY)
		std::cout << "Gray";
	else if (color == COLOR_BLUE)
		std::cout << "Blue";
	else if (color == COLOR_GREEN)
		std::cout << "Green";
	else if (color == COLOR_BROWN)
		std::cout << "Brown";
	else if (color == COLOR_PINK)
		std::cout << "Pink";
	else if (color == COLOR_YELLOW)
		std::cout << "Yellow";
	else if (color == COLOR_MAGENTA)
		std::cout << "Magenta";
	else
		std::cout << "Who knows!";
}
int main()
{
	enum Colors
	{
		COLOR_YELLOW, // присвоено 0
		COLOR_WHITE, // присвоено 1
		COLOR_ORANGE, // присвоено 2
		COLOR_GREEN, // присвоено 3
		COLOR_RED, // присвоено 4
		COLOR_GRAY, // присвоено 5
		COLOR_PURPLE, // присвоено 6
		COLOR_BROWN // присвоено 7
	};

	Colors paint(COLOR_RED);

	std::cout << paint << '\n';

	// определяем новый перечисляемый тип Animals
	enum Animals
	{
		ANIMAL_PIG = -4,
		ANIMAL_LION, // присвоено -3
		ANIMAL_CAT, // присвоено -2
		ANIMAL_HORSE = 6,
		ANIMAL_ZEBRA = 6, // имеет то же значение, что и ANIMAL_HORSE
		ANIMAL_COW // присвоено 7
	};

	int mypet = ANIMAL_PIG;
	std::cout << ANIMAL_HORSE << std::endl; // превращается в int, затем выводиться с помощью std::cout 

	//Animals animal = 7; // приведет к ошибке компилятора

	//Colors color = static_cast<Colors>(5); // но так делать не советуем

	int inputColor;
	std::cin >> inputColor;

	Colors color = static_cast<Colors>(inputColor);
	printColor(static_cast<Colours>(inputColor));
	std::cout <<  std::endl;
	//Animals animal = COLOR_BLUE; // приведет к ошибке компилятора
	
	// ItemType - это перечисляемый тип, который мы объявили выше
	// itemType (с маленькой i) - это имя переменной, которую мы определили (типа ItemType)
	// ITEMTYPE_GUN - это значение перечислителя, которое мы присвоили переменной itemType
	ItemType itemType(ITEMTYPE_GUN);

	std::cout << "You are carrying a " << getItemName(itemType) << "\n";
	// ТЕСТ 58
	enum MonsterType
	{
		MONSTER_OGRE,
		MONSTER_GOBLIN,
		MONSTER_SKELETON,
		MONSTER_ORC,
		MONSTER_TROLL
	};

	MonsterType monster(MONSTER_OGRE);
	std::cout << monster;
	return 0;
}
