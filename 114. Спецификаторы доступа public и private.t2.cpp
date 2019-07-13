/*
a) Напишите простой класс с именем Numbers. Этот класс должен иметь:

   Три закрытые переменные-члены типа double: m_a, m_b и m_c.

   Открытый метод с именем setValues(), который позволит устанавливать значения для m_a, m_b и m_c;

   Открытый метод с именем print(), который будет выводить объект класса Numbers в следующем формате: <m_a, m_b, m_c>.
   
   Должен производить следующий результат:

<3, 4, 5>

b) Добавьте функцию isEqual() в класс Numbers, чтобы сравнивать:
*/

#include <iostream>

class Numbers
{

    double m_a;
    double m_b;
    double m_c;
public:
    void setValues(const double &a, const double &b, const double &c)
    {
       m_a = a;
       m_b = b;
       m_c = c;
    }
    // Метод вывода информации о работнике на экран
    void print()
    {
        std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">" << std::endl;
}

    bool isEqual(const Numbers &x)
    {
        if ( m_a == x.m_a && m_b == x.m_b && m_c == x.m_c)
            return true;
        else return false;
    }

};
int main()
{
       Numbers point1;
       point1.setValues(3.0, 4.0, 5.0);

       Numbers point2;
       point2.setValues(3.0, 4.0, 5.0);

       if (point1.isEqual(point2))
           std::cout << "point1 and point2 are equal\n";
       else
           std::cout << "point1 and point2 are not equal\n";

       Numbers point3;
       point3.setValues(7.0, 8.0, 9.0);

       if (point1.isEqual(point3))
           std::cout << "point1 and point3 are equal\n";
       else
           std::cout << "point1 and point3 are not equal\n";
       return 0;
}
