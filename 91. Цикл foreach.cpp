/*
Объявите фиксированный массив со следующими именами: Sasha, Ivan, John, Orlando, Leonardo, Nina, Anton и Molly. 
Попросите пользователя ввести имя. Используйте цикл foreach для проверки того, не находится ли имя, введенное пользователем,
уже в массиве.

Пример результата выполнения программы:

Enter a name: Sasha
Sasha was found.

Enter a name: Maruna
Maruna was not found.

Подсказка: Используйте std::string в качестве типа массива.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string array[] = {"Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly"};
    for (const auto &number : array)
        std::cout << number << endl;

    cout << "Enter a name: ";
    std::string nameUser;
    cin >> nameUser;
    for (const auto &number : array)
        {
        if (number == nameUser){
            std::cout << nameUser << " was found." << endl;
            break;
        }
        else {
            std::cout << nameUser << " was not found." << endl;
            break;}
        }


    return 0;
}
