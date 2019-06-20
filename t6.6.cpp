#include <iostream>
#include <array>
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937
#include <cstdlib> // для rand() и srand()
enum Suits
{
	BUBNY,
	CHERVI,
	PIKI,
	TREF,
	SUITS_SIZE
};
enum Rank
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	VALET,
	DAMA,
	KOROL,
	TUZ,
	RANK_SIZE
};
struct Card
{
	Suits suits{};
	Rank rank{};
};
void printCard(const Card &card)
{
	using namespace std;
	switch (card.rank)
	{
	case TWO:		cout << "2"; break;
	case THREE:		cout << "3"; break;
	case FOUR:		cout << "4"; break;
	case FIVE:		cout << "5"; break;
	case SIX:		cout << "6"; break;
	case SEVEN:		cout << "7"; break;
	case EIGHT:		cout << "8"; break;
	case NINE:		cout << "9"; break;
	case TEN:		cout << "10"; break;
	case VALET:		cout << "V"; break;
	case DAMA:		cout << "D"; break;
	case KOROL:		cout << "K"; break;
	case TUZ:		cout << "T"; break;
	}
	switch (card.suits) 
	{
	case BUBNY:		cout << "B"; break;
	case CHERVI:	cout << "C"; break;
	case PIKI:		cout << "P"; break;
	case TREF:		cout << "T"; break;
	}

}
void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}
void swapCard(Card &x, Card &y)
{
	Card temp = x;
	x = y;
	y = temp;
}
int getRandomNumber(long min, long max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне


	int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
	return randomNumber; // возвращаем случайное число в заданом диапазоне 
}
void shuffleDeck(std::array<Card, 52> & deck)
{
	// Перебираем каждую карту в колоде
	for (int index = 0; index < 52; ++index)
	{
		// Выбираем любую случайную карту
		int swapIndex = getRandomNumber(0, 51);
		// Меняем местами с нашей текущей картой
		swapCard(deck[index], deck[swapIndex]);
	}
}
int getCardValue(const Card& card)
{
	switch (card.rank)
	{
	case TWO:		return 2;
	case THREE:		return 3;
	case FOUR:		return 4;
	case FIVE:		return 5;
	case SIX:		return 6;
	case SEVEN:		return 7;
	case EIGHT:		return 8;
	case NINE:		return 9;
	case TEN:		return 10;
	case VALET:		return 10;
	case DAMA:	    return 10;
	case KOROL:		return 10;
	case TUZ:		return 11;
	}

	return 0;
}

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(const std::array<Card, 52> & deck)
{
	// Настраиваем стартовый режим игры
	const Card* cardPtr = &deck[0];

	int playerTotal = 0;
	int dealerTotal = 0;

	// Дилер получает одну карту
	dealerTotal += getCardValue(*cardPtr++);
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Игрок получает две карты
	playerTotal += getCardValue(*cardPtr++);
	playerTotal += getCardValue(*cardPtr++);

	// Игрок начинает
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';

		// Смотрим, не больше ли 21 у игрока
		if (playerTotal > 21)
			return false;

		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += getCardValue(*cardPtr++);
	}

	// Если игрок не проиграл и у него не больше 21, то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17
	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardPtr++);
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// Если у дилера больше 21, то игрок победил
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}
int main()
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
	srand(static_cast<int>(mersenne()));  // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
	rand();  //
	std::array<Card, 52> deck;

	int card = 0;
	for (int suit = 0; suit < SUITS_SIZE; ++suit)
		for (int rank = 0; rank < RANK_SIZE; ++rank)
		{
			deck[card].suits = static_cast<Suits>(suit);
			deck[card].rank = static_cast<Rank>(rank);
			card++;
		}
	getRandomNumber(1, 52);// случайная карта
	printDeck(deck);
	shuffleDeck(deck);
	printDeck(deck);
	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
