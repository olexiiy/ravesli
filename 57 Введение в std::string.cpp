#include <iostream>
#include <string>


	int main()
	{
		std::cout << "Enter your full name: ";
		std::string myName;
		std::getline(std::cin, myName);

		

		std::cout << "Enter your age: ";
		int age;
		std::cin >> age;
		double eachLetter = static_cast<double>(age) /static_cast<double>(myName.length());
		std::cout << "You've lived " << eachLetter << " years for each letter in your name.";
				
		return 0;
	}
  
  /*
Напишите программу, которая спрашивает у пользователя его имя-фамилию и возраст. В результате также укажите пользователю, сколько лет он прожил с каждой буквы своего имя-фамилии (чтобы было проще, пробелы тоже считаются буквами).

Например:

Enter your full name: John Doe
Enter your age: 46
You've lived 5.75 years for each letter in your name.

Уточнение: То есть, если возраст 46, а имя «John Doe» (8 букв вместе с пробелом), то 46 делим на 8. Получаем 5.75.
*/
