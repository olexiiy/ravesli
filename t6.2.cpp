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

struct BookMark
{
     std::string name;
     int mark;
};

void sortMark(BookMark *students, int length)
{
    // Перебираем каждый элемент массива
    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
        // largestIndex - это индекс наибольшего элемента, который мы обнаружили до сих пор
        int largestIndex = startIndex;

        // Ищем наибольший элемент среди оставшихся элементов массива (начиная со startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            // Если текущий элемент больше нашего предыдущего наибольшего элемента,
            if (students[currentIndex].mark > students[largestIndex].mark)
                // то тогда это наш новый наибольший элемент в этой итерации
                largestIndex = currentIndex;
        }

        // Меняем местами наш стартовый элемент с найденным наибольшим элементом
        std::swap(students[startIndex], students[largestIndex]);
    }
}

void sortNames(BookMark *students, int length)
{
    // Перебираем каждый элемент массива
    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
        // largestIndex - это индекс наибольшего элемента, который мы обнаружили до сих пор
        int largestIndex = startIndex;

        // Ищем наибольший элемент среди оставшихся элементов массива (начиная со startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            // Если текущий элемент больше нашего предыдущего наибольшего элемента,
            if (students[currentIndex].name < students[largestIndex].name)
                // то тогда это наш новый наибольший элемент в этой итерации
                largestIndex = currentIndex;
        }

        // Меняем местами наш стартовый элемент с найденным наибольшим элементом
        std::swap(students[startIndex], students[largestIndex]);
    }
}
int main()
{
    using namespace std;
    cout << "How much students do you have: ";
    int number{};
    do
        {
            std::cout << "How many students do you want to enter? ";
            std::cin >> number;
        } while (number <= 1);

   BookMark *students = new (std::nothrow) BookMark[number];
   for (int startIndex = 0; startIndex < number; ++startIndex)
       {
          cout <<  "Enter name #" << (startIndex + 1) << ":";
          std::cin >> students[startIndex].name;
          std::cout << "Enter grade #" << startIndex + 1 << ": ";
          std::cin >> students[startIndex].mark;
        }
   sortMark(students, number);
   for (int startIndex = 0; startIndex < number; ++startIndex)
       {
          cout << students[startIndex].name << " got a grade of " << students[startIndex].mark << endl;
        }
   cout << endl;
   cout << endl;
   sortNames(students, number);
   for (int startIndex = 0; startIndex < number; ++startIndex)
       {
          cout << students[startIndex].name << " got a grade of " << students[startIndex].mark << endl;
        }
   delete[] students;
   return 0;
}
