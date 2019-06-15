#include <iostream>

using namespace std;
enum CardSuit
{
    SUIT_TREFU,
    SUIT_BYBNU,
    SUIT_CHERVU,
    SUIT_PIKI,
    MAX_SUITS
};
enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_VALET,
    RANK_DAMA,
    RANK_KOROL,
    RANK_TYZ,
    MAX_RANKS
};
struct Card
{
    CardRank rank{};
    CardSuit suit{};
};
void printCard (const Card &card)
{
    switch(card.rank)
    {
        case RANK_2:		std::cout << "2";  break;
        case RANK_3:		std::cout << "3";  break;
        case RANK_4:		std::cout << "4";  break;
        case RANK_5:		std::cout << "5";  break;
        case RANK_6:		std::cout << "6";  break;
        case RANK_7:		std::cout << "7";  break;
        case RANK_8:		std::cout << "8";  break;
        case RANK_9:		std::cout << "9";  break;
        case RANK_10:		std::cout << "10"; break;
        case RANK_VALET:    std::cout << "V";  break;
        case RANK_DAMA:		std::cout << "D";  break;
        case RANK_KOROL:	std::cout << "K";  break;
        case RANK_TYZ:		std::cout << "T";  break;   
    } 
    switch(card.suit)
    {
        case SUIT_TREFU:    std::cout << "T"; break;
        case SUIT_BYBNU:    std::cout << "B"; break;
        case SUIT_CHERVU:   std::cout << "C"; break;
        case SUIT_PIKI:     std::cout << "P"; break;
    }    
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
