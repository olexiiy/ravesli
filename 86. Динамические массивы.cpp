/*Напишите программу, которая:

   спрашивает у пользователя, сколько имён он хочет ввести;

   просит пользователя ввести каждое имя;

   вызывает функцию для сортировки имён в алфавитном порядке (код сортировки методом выбора);

   выводит отсортированный список имён.

Подсказка №1: Используйте динамическое выделение std::string для хранения имён.

Подсказка №2: std::string поддерживает сравнение строк с помощью операторов сравнения: < и >.

Пример результата выполнения вашей программы:

How many names would you like to enter? 5
Enter name #1: Jason
Enter name #2: Mark
Enter name #3: Alex
Enter name #4: Chris
Enter name #5: John

Here is your sorted list:
Name #1: Alex
Name #2: Chris
Name #3: Jason
Name #4: John
Name #5: Mark
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string  getName()	// Вводим имя
{
    std::string nameUser;
    std::getline(std::cin, nameUser);
    return nameUser;
}
unsigned int getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        unsigned int a;
        std::cin >> a;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767,'\n'); // удаляем лишние значения

            return a;
        }
    }
}
void  arraySort (string *array, int length)
{
    // Перебираем каждый элемент массива
        // (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберёмся)
        for (int startIndex = 0; startIndex < length - 1; ++startIndex)
        {
            // Перебираем каждый элемент массива до последнего элемента (не включительно)
            // Последний элемент не имеет пары для сравнения
            for (int currentIndex = 0; currentIndex < length - 1; ++currentIndex)
            {
                // Если текущий элемент больше элемента после него, то меняем их местами
                if (array[currentIndex] > array[currentIndex + 1])
                    // то запоминаем его
                     std::swap(array[currentIndex], array[currentIndex + 1]);
            }
    }
}

int main()
{

    cout << "How many names would you like to enter? ";
    int size = getValue();

    const int length(size);
       string *array = new string[length];
    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
       cout <<  "Enter name #" << (startIndex + 1) << ":";
       array[startIndex] = getName();
    }
    arraySort(array, length);

    cout << "Here is your sorted list:  " << endl;
    // Теперь, когда весь массив отсортирован - eвыводим его на экран
    for (int index = 0; index < length; ++index)
           std::cout << "Name #" << index + 1 << ": " << array[index] << endl;
    delete[] array;
    return 0;
}
