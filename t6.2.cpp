/*
Создайте структуру, содержащую имя и оценку учащегося (по шкале от 0 до 100). Спросите у пользователя, сколько учеников 
он хочет ввести. Динамически выделите массив для хранения всех студентов. Затем попросите пользователя ввести для 
каждого студента его имя и оценку. Как только пользователь ввёл все имена и оценки, отсортируйте список по убывания 
оценок студентов (сначала самый высокий бал). Затем выведите все имена и оценки в отсортированном виде.

Для следующего ввода:

Andre
74
Max
85
Anton
12
Josh
17
Sasha
90

Вывод должен быть следующим:

Sasha got a grade of 90
Max got a grade of 85
Andre got a grade of 74
Josh got a grade of 17
Anton got a grade of 12

Подсказка: Вы можете изменить алгоритм сортировки массива методом выбора из урока №77 для сортировки вашего 
динамического массива. Если вы напишите сортировку массива отдельной функцией, то массив должен передаваться по 
адресу (как указатель).
*/

#include <iostream>
#include <string>
#include <utility>


struct Student
{
    std::string name;
    int mark;
};

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

void input_n(Student *students, int quantity)
{
    for (int num = 0; num < quantity; ++num)
    {
        std::cout << "Enter name #" << (num + 1) << ": ";
        students[num].name = getString();
        std::cout << "Enter mark #" << (num + 1) << ": ";
        students[num].mark = getValue();
    }
}

void sort_n(Student* students, int quantity)
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
            if (students[currentIndex].mark < students[currentIndex + 1].mark)
            {
                // Выполняем замену
                std::swap(students[currentIndex], students[currentIndex + 1]);
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

void print_n(const Student* const students, int quantity)
{
    std::cout << "Here is your sorted list:\n";
	
    for (int num = 0; num < quantity; ++num) // перебираем и выводим значение каджого елемента 
    {
        std::cout << students[num].name << " got a grade of  " << students[num].mark << std::endl;
    }
}

int main()
{
    do
    {
        setlocale(LC_ALL, "Russian");

        std::cout << "How much students dow you have ?:  ";
	    
        int quantity{ getValue() };
	    
        Student* students = new(std::nothrow) Student[quantity];
	    
    	if(!students)
        {
            std::cout << "Allocation returned nullptr\n";
    		continue;
        }

        input_n(students, quantity);
	    
        sort_n(students, quantity);
	    
        print_n(students, quantity);

        delete[] students;
	    
        students = nullptr;
	    
    } while (again());
    return 0;
}

