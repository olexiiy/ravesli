//blackjack
#include <iostream>
#include <string>
#include <utility>
#include <windows.h>         // для Sleep();
//#include <unistd.h>         // для usleep();  //         std::cout << v << std::flush;  usleep(400000);
#include <array>
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937




int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне


    int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
    return randomNumber; // возвращаем случайное число в заданом диапазоне 
}

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
            if(a >= 0 && a <=100 )
            return a;
        }

    }
}

enum card_suit
{
   suit_trefy, suit_bubny, suit_chervy, suit_piki, max_suits
};

enum card_rank
{
    rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10,
    rank_valet, rank_dama, rank_korol, rank_tuz, max_ranks
};

struct cards
{
    card_rank rank;
    card_suit suit;
};

void print_card (const cards &card)
{

    std::string card_p{};
	switch (card.rank)
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

    switch (card.suit)
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
        Sleep(50);                                          // останавливаем программу на 0,4 сек.;
    }

}

void print_deck(const std::array<cards, 52> &deck)
{
    for (auto c : deck)
    {
        print_card(c);
        std::cout << ' ';
    }
    std::cout << std::endl;
}

void swap_card( cards& one, cards &two)
{
    cards temp = one;
    one = two;
    two = temp;
}

void shuffle_deck(std::array<cards, 52>& deck)
{
    int x{};

    while (x < 4) {

        for (int index = 0; index < 52; ++index)

        {
            int swapIndex = getRandomNumber(0, 51);

            swap_card(deck[index], deck[swapIndex]);
        }
        ++x;
    }
        
}

int get_card_value(const cards & card)
{
    
    switch (card.rank)
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

bool playBlackjack(const std::array<cards, 52>& deck)
{
    // Настраиваем стартовый режим игры
    const cards* cardPtr = &deck[0];

    int playerTotal = 0;
    int dealerTotal = 0;

    // Дилер получает одну карту
    dealerTotal += get_card_value(*cardPtr++);
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    // Игрок получает две карты
    playerTotal += get_card_value(*cardPtr++);
    playerTotal += get_card_value(*cardPtr++);

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

        playerTotal += get_card_value(*cardPtr++);

    }

    // Если игрок не проиграл и у него не больше 21, то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17
    while (dealerTotal < 18)
    {
        dealerTotal += get_card_value(*cardPtr++);
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // Если у дилера больше 21, то игрок победил
    if (dealerTotal > 21)
        return true;

    return (playerTotal > dealerTotal);
}

void init_cards (std::array<cards, 52> &deck)
{
    int card = 0;
    for (int suit = 0; suit < max_suits; ++suit)
        for (int rank = 0; rank < max_ranks; ++rank)
        {
            deck[card].suit = static_cast<card_suit>(suit);
            deck[card].rank = static_cast<card_rank>(rank);
            ++card;
        }
}

int main()
{
    do
    {
        setlocale(LC_ALL, "Russian");

        std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
        srand(static_cast<int>(mersenne()));  // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
        rand();  // сбрасываем первый результат

    	
        std::array<cards, 52> deck;

        init_cards(deck);
    	
        //print_deck(deck);
        shuffle_deck(deck);
        //print_deck(deck);

    	
        if (playBlackjack(deck))
            std::cout << "You win!\n";
        else
            std::cout << "You lose!\n";
    	
                  
        
    } while (again());
    return 0;
}


