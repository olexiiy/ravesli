/*
Напишите функцию для вывода строки C-style символ за символом. Используйте указатель для перехода и вывода каждого 
символа поочерёдно. Остановите вывод при столкновении с нуль-терминатором. В функции main() протестируйте строку Hello, world!.

Подсказка: Используйте оператор ++ для перевода указателя на следующий символ.
*/


#include <iostream>
#include <windows.h.

// str указывает на первый символ строки C-style
// Обратите внимание, str указывает на const char и мы не можем изменить это значение
// Однако, мы можем указать str указывать на что-либо другое. Это не приведёт к изменению значения исходного аргумента

void print_char(char * message0
{
for (auto v : message)
        {
            std::cout << v << std::flush;      // Выводим символ;
           Sleep(400);                                          // останавливаем программу на 0,4 сек.;
        }
}

int main()
{
    printCString("Hello, world!");

    char message[]= "Hello, world!" ;
    	
    	
    
    return 0;
}
