//blackjack
//blackjack
#include <iostream>
#include <string>
#include <utility>
#include <windows.h>         // для Sleep();
//#include <unistd.h>         // для usleep();  //         std::cout << v << std::flush;  usleep(400000);
#include <array>
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937
#include <cassert>


bool again()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "\nWould you like to play again (y/n)?";
        char answer;
        std::cin >> answer;

        // Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

        std::cin.ignore(32767, '\n'); // удаляем лишний балласт

        // Выполняем проверку пользовательского ввода
        if (answer == 'y')
            return true; // возвращаем обратно в caller
            //exit(0);
        else if (answer == 'n')
            return false; // возвращаем обратно в caller
        else // в противном случае, сообщаем пользователю что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}

int getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {

        short a;
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
            if (a >= 0 && a <= 100)
                return a;
        }

    }
}

class Card
{
public:
    enum card_suit
    {
        suit_trefy, suit_bubny, suit_chervy, suit_piki, max_suits
    };

    enum card_rank
    {
        rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10,
        rank_valet, rank_dama, rank_korol, rank_tuz, max_ranks
    };

    private:
    card_rank m_rank;
    card_suit m_suit;
public:
     Card(const card_rank rank = max_ranks, const card_suit suit = max_suits)  : m_rank(rank), m_suit(suit) {};

    const Card& print() const
    {

        std::string card_p{};
        switch (m_rank)
        {
        case  rank_2:
            card_p += "2"; break;
        case  rank_3:
            card_p += "3"; break;
        case  rank_4:
            card_p += "4"; break;
        case  rank_5:
            card_p += "5"; break;
        case  rank_6:
            card_p += "6"; break;
        case  rank_7:
            card_p += "7"; break;
        case  rank_8:
            card_p += "8"; break;
        case  rank_9:
            card_p += "9"; break;
        case  rank_10:
            card_p += "10"; break;
        case  rank_valet:
            card_p += "V"; break;
        case  rank_dama:
            card_p += "D"; break;
        case  rank_korol:
            card_p += "K"; break;
        case  rank_tuz:
            card_p += "T"; break;
        }

        switch (m_suit)
        {
        case suit_bubny:
            card_p += "B"; break;
        case  suit_chervy:
            card_p += "C"; break;
        case  suit_piki:
            card_p += "P"; break;
        case  suit_trefy:
            card_p += "T"; break;
        }

        for (auto v : card_p)
        {
            std::cout << v << std::flush;      // Выводим символ;
            Sleep(20);                                          // останавливаем программу на 0,4 сек.;
        }
        return *this ;
    }

    const int get_value() const 
    {

        switch (m_rank)
        {
        case  rank_2:
            return 2;
        case  rank_3:
            return 3;
        case  rank_4:
            return 4;
        case  rank_5:
            return 5;
        case  rank_6:
            return 6;
        case  rank_7:
            return 7;
        case  rank_8:
            return 8;
        case  rank_9:
            return 9;
        case  rank_10:
            return 10;
        case  rank_valet:
            return 10;
        case  rank_dama:
            return 10;
        case  rank_korol:
            return 10;
        case  rank_tuz:
            return 11;
        }
        return 0;
    }
	
};

class Deck
{
    private:
    std::array<Card, 52> m_deck;
    int m_cardIndex{};

	static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        // Равномерно распределяем рандомное число в нашем диапазоне


        int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
        return randomNumber; // возвращаем случайное число в заданом диапазоне 
    }
    static void swap_card(Card& one, Card& two)
    {
        Card temp = one;
        one = two;
        two = temp;
        
    }
    Deck& init_cards()
    {
        int card = 0;
        for (int suit = 0; suit < Card::max_suits; ++suit)
            for (int rank = 0; rank < Card::max_ranks; ++rank)
            {
                m_deck[card] = Card(static_cast<Card::card_rank>(rank), static_cast<Card::card_suit>(suit));
                ;
                ++card;
            }
        return *this;
    }

	public:
    Deck()
    {
        init_cards();
    }
	
    Deck& shuffle_deck()
    {
        int x{};

        while (x < 4) {

            for (int index = 0; index < 52; ++index)

            {
                int swapIndex = getRandomNumber(0, 51);

                swap_card(m_deck[index], m_deck[swapIndex]);
            }
            ++x;
        }

        m_cardIndex = 0;
        return *this;
    }

    const Card& dealCard()
    {
        assert(m_cardIndex < 52 && "your card is out of range");
        return m_deck[m_cardIndex++];
    }
	
    const Deck& print() const
    {
        for (auto c : m_deck)
        {
            c.print();
            std::cout << ' ';
        }
        std::cout << std::endl;
        return *this;
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

bool playBlackjack(Deck& deck)
{
        int playerTotal = 0;
    int dealerTotal = 0;

    // Дилер получает одну карту
    dealerTotal += deck.dealCard().get_value();
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    // Игрок получает две карты
    playerTotal += deck.dealCard().get_value();
    playerTotal += deck.dealCard().get_value();

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

        playerTotal += deck.dealCard().get_value();

    }

    // Если игрок не проиграл и у него не больше 21, то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17
    while (dealerTotal < 18)
    {
        dealerTotal += deck.dealCard().get_value();
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // Если у дилера больше 21, то игрок победил
    if (dealerTotal > 21)
        return true;

    return (playerTotal > dealerTotal);
}

int main()
{
    do
    {
        setlocale(LC_ALL, "Russian");

        std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
        srand(static_cast<int>(mersenne()));  // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
        rand();  // сбрасываем первый результат


        Card cardQueenHearts(Card::rank_dama, Card::suit_chervy);
        cardQueenHearts.print();
        std::cout << " has the value " << cardQueenHearts.get_value() << '\n';
    	
        Deck deck;

        deck.shuffle_deck();
        deck.print();
       
            if (playBlackjack(deck))
                std::cout << "You win!\n";
            else
                std::cout << "You lose!\n";

    } while (again());
    return 0;
}



