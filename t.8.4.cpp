//blackjack using classes
#include <iostream>
#include "timer.h"
/*Timer t1; std::cout << "elapsed: " << t1.elapsed() << '\n';*/


#include <array>
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937
#include <cstdlib> // для rand() и srand()
#include  <cassert>

class Card
{
public:
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
private:
    Suits m_suits;
    Rank m_rank;
public:
    Card( Rank rank = RANK_SIZE, Suits suits = SUITS_SIZE)  :  m_rank(rank), m_suits (suits) {}
    void printCard() const
    {
        using namespace std;
        switch (m_rank)
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
        switch (m_suits)
        {
        case BUBNY:		cout << "B"; break;
        case CHERVI:	cout << "C"; break;
        case PIKI:		cout << "P"; break;
        case TREF:		cout << "T"; break;
        }

    }
    int getCardValue() const
    {
        switch (m_rank)
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

};

class Deck
{
  private:
    std::array<Card, 52> m_deck;
    int m_cardIndex{0};
    static int getRandomNumber(long min, long max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить только один раз
        // Равномерно распределяем рандомное число в нашем диапазоне
        int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
        return randomNumber; // возвращаем случайное число в заданом диапазоне
    }
    static void swapCard(Card &x, Card &y)
    {
        Card temp = x;
        x = y;
        y = temp;
    }
public:
    Deck()
    {
        int card = 0;
            for (int suits = 0; suits < Card::SUITS_SIZE; ++suits)
                for (int rank = 0; rank < Card::RANK_SIZE; ++rank)
                {
                    m_deck[card] = Card (static_cast<Card::Rank>(rank),
                                         static_cast<Card::Suits>(suits));
                    card++;
                }
    }
    void printDeck() const
    {
        for (const auto& card : m_deck)
            {
                card.printCard();
                std::cout << ' ';
            }
            std::cout << '\n';
    }
    void shuffleDeck()
    {
        // Перебираем каждую карту в колоде
        for (int index = 0; index < 52; ++index)
        {
            // Выбираем любую случайную карту
            int swapIndex = getRandomNumber(0, 51);
            // Меняем местами с нашей текущей картой
            swapCard(m_deck[index], m_deck[swapIndex]);
        }
         m_cardIndex = 0;
    }
    const Card& dealCard()
    {
        assert (m_cardIndex < 52);
                return m_deck[m_cardIndex++];
    }

};

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

bool playBlackjack(Deck &deck)
{
    // Настраиваем стартовый режим игры


    int playerTotal = 0;
    int dealerTotal = 0;

    // Дилер получает одну карту
    dealerTotal += deck.dealCard().getCardValue();
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    // Игрок получает две карты
    playerTotal += deck.dealCard().getCardValue();
    playerTotal += deck.dealCard().getCardValue();

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

        playerTotal += deck.dealCard().getCardValue();

    }

    // Если игрок не проиграл и у него не больше 21, то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17
    while (dealerTotal < 18)
    {
        dealerTotal += deck.dealCard().getCardValue();
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // Если у дилера больше 21, то игрок победил
    if (dealerTotal > 21)
        return true;

    return (playerTotal > dealerTotal);
}

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
        if (answer == 'y' )
            return true; // возвращаем обратно в caller
        else if (answer == 'n')
            return false; // возвращаем обратно в caller
        else // в противном случае, сообщаем пользователю что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}
int main()
{
    do
       {
         std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
         srand(static_cast<int>(mersenne()));  // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
         rand(); // инициализируем первый елемент
         Timer t;
         Deck deck;
         deck.shuffleDeck();
         std::cout << "elapsed: " << t.elapsed() << '\n';
         deck.printDeck();
            if (playBlackjack(deck))
                std::cout << "You win!\n";
            else
                std::cout << "You lose!\n";
    }while (playAgain());

       std::cout << "thank you for the game" << std::endl;
       return 0;
}
