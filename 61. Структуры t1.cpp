

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
