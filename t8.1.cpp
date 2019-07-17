/*
Задание №1

a) Напишите класс с именем Point. В Point-е должны быть две переменные-члены типа double: m_a и m_b, со значениями 
по умолчанию 0.0. Напишите конструктор для этого класса и функцию вывода print().

Должна производить следующий результат:

Point(0, 0)
Point(2, 5)

b) Теперь добавим метод distanceTo(), который будет принимать второй объект класса Point в качестве параметра и будет 
вычислять расстояние между двумя объектами. Учитывая две точки (a1, b1) и (a2, b2), расстояние между ними можно вычислить 
следующим образом: sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2)). Функция sqrt находится в заголовочном файле cmath.

Должна производить следующий результат:

Point(0, 0)
Point(2, 5)
Distance between two points: 5.38516

c) Измените функцию distanceTo() из метода класса в дружественную функцию, которая будет принимать два объекта класса Point
в качестве параметров. Переименуйте эту функцию на distanceFrom().

Должна производить следующий результат:

Point(0, 0)
Point(2, 5)
Distance between two points: 5.38516
*/


#include <iostream>
#include "timer.h"
/*Timer t1;
 std::cout << "elapsed: " << t1.elapsed() << '\n';*/
#include <cmath>
using namespace std;

class Point
{
private:
    double m_a;
    double m_b;
public:
    Point(double a = 0.0, double b = 0.0)
        : m_a(a), m_b(b)
    {
    }

    friend void  distanceFrom(const Point &f, const Point &s);

    void print ()
    {
        cout << "Point(" <<m_a << ", " << m_b << ")" <<endl;
    }
};
void  distanceFrom(const Point &f, const Point &s)
{
    cout << "Distance between two points: "
         << sqrt((f.m_a - s.m_a) * (f.m_a - s.m_a) + (f.m_b - s.m_b) * (f.m_b - s.m_b)) << endl;
}

int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    distanceFrom(first, second);

    return 0;
}
