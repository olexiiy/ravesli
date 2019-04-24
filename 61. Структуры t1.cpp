/*У вас есть веб-сайт и вы хотите отслеживать, сколько денег вы зарабатываете в день от размещённой на нём рекламы. Объявите структуру Advertising, которая будет отслеживать:

   сколько объявлений вы показали посетителям (1);

   сколько процентов посетителей нажали на объявления (2);

   сколько вы заработали в среднем за каждое нажатие на объявления (3).

Значения этих трёх полей должен вводить пользователь. Передайте структуру Advertising в функцию, которая выведет каждое из этих значений, а затем подсчитает, сколько всего денег вы заработали за день (перемножьте все 3 поля).
*/
#include <iostream>

struct Advertising
{
	double viewed;
	double clicked;
	double paid;
};

void outPut(Advertising mySite)
{
	using namespace std;
	cout << "Number of ads shown: " << mySite.viewed << endl;
	cout << "Click through rate: " << mySite.clicked << endl;
	cout << "Average earnings per click: $" << mySite.paid << endl;

	// Следующая строка кода разбита из-за своей длины
	// Мы делим mySite.clicked на 100, так как пользователь указывает проценты, а не готовое число
	cout << "Total Earnings: $" <<
		(mySite.viewed * mySite.clicked / 100 * mySite.paid) << endl;
	
}


int main()
{
	using namespace std;
	Advertising mySite;
    std::cout << "Input the Views: \n"; 
	std::cin >> mySite.viewed;
	std::cout << "Input the Clicked percent : \n";
	std::cin >> mySite.clicked;
	std::cout << "Input the Paid: \n";
	std::cin >> mySite.paid;
	outPut(mySite);

	return 0;

}
