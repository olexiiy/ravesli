/*
Напишите свою функцию замены местами значений двух целочисленных переменных. Проверку осуществляйте в функции main().

Подсказка: Используйте ссылки в качестве параметров.
*/

#include <iostream>
// используем ссылку, чтобы иметь возможность изменять значение
void change (int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}
int main()
{
    using namespace std;
    int x = 1;
    int y = 100;
    change(x, y);
    if (x == 100 && y == 1)
        cout << "it's work";
    else 
        cout << "don't work";
    return 0;
}
