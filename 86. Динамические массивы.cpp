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
#include <string>
#include <utility>

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
		      
        int a;
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

            return a;
        }

    }
}

std::string getString()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {

        std::string a;
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

            return a;
        }

    }
}
void input_n (std::string* names, int quantity)
{
    for (int num = 0; num < quantity; ++num)
    {
        std::cout << "Enter name #" << (num + 1) << ": ";
        names[num] = getString();
    }
}

void sort_n(std::string *names, int quantity)
{
    for (int iteration = 0; iteration < quantity - 1; ++iteration)
    {
        // Помните о том, что последний элемент будет отсортирован и в каждой последующей итерации цикла,
        // поэтому наша сортировка «заканчивается» на один элемент раньше
        int endOfArrayIndex(quantity - iteration);

        bool swapped(false); // отслеживаем, были ли выполнены замены в этой итерации

        // Перебираем каждый элемент массива до последнего (не включительно)
        // Последний элемент не имеет пары для сравнения
        for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            // Если текущий элемент больше элемента после него, то меняем их местами
            if (names[currentIndex] > names[currentIndex + 1])
            {
                // Выполняем замену
                std::swap(names[currentIndex], names[currentIndex + 1]);
                swapped = true;
            }
        }

        // Если в этой итерации не выполнилось ни одной замены, то цикл можно завершать
        if (!swapped)
        {
            // Выполнение начинается с 0-ой итерации, но мы привыкли считать, начиная с 1, поэтому для подсчёта количества итераций добавляем единицу
            std::cout << "Early termination on iteration: " << iteration + 1 << '\n';
            break;
        }
    }

    
}

void print_n(std::string* names, int quantity)
{
    std::cout << "Here is your sorted list:\n";
	
    for (int num = 0; num < quantity; ++num)
    {
        std::cout << "Name #" << (num + 1) << ": " << names[num] << std::endl;
    }
}



int main()
{
    do
    {
        setlocale(LC_ALL, "Russian");

        std::cout << "How many names would you like to enter? ";
        int quantity{getValue()};
    	
        std::string * names = new (std::nothrow) std::string[quantity];
        if (!names)
        {
            // Обработка этого случая
            std::cout << "Could not allocate memory";
            continue;
        }

        input_n(names, quantity);
    	
        sort_n(names, quantity);
    	
        print_n(names, quantity);
    		
        
        delete[] names;
        names = nullptr;
       
    } while (again());
    return 0;
}


