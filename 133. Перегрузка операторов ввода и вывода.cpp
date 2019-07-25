#include <iostream>
#include "timer.h"
/*Timer t1; std::cout << "elapsed: " << t1.elapsed() << '\n';*/


class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator=0, int denominator=1):
        m_numerator(numerator), m_denominator(denominator)
    {
        // Мы поместили reduce() в конструктор, чтобы убедиться, что все дроби, которые у нас есть, будут уменьшены!
        // Поскольку выполнение всех перегруженных операторов осуществляется вместе с созданием новых объектов класса Fraction, то мы можем гарантировать, что эта функция вызовется для каждой дроби
        reduce();
    }
         // Делаем функцию nod статической, чтобы она могла быть частью класса Fraction и при этом, для её использования, нам не нужно было бы создавать объект класса Fraction
    static int nod(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
    }

    void reduce()
    {
        int nod = Fraction::nod(m_numerator, m_denominator);
        m_numerator /= nod;
        m_denominator /= nod;
    }
    void print ();

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, int value);
    friend Fraction operator*(int value, const Fraction &f);
    friend std::istream& operator>>(std::istream &in, Fraction &fraction);
    friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
};
void Fraction::print ()
{
std::cout << m_numerator << "/" << m_denominator;
}
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    int numerator = f1.m_numerator * f2.m_numerator;
    int denominator = f1.m_denominator * f2.m_denominator;
    return Fraction(numerator, denominator);
}
Fraction operator*(const Fraction &f1, int value)
{
    int numerator = f1.m_numerator * value;
   return Fraction(numerator, f1.m_denominator);
}
Fraction operator*(int value, const Fraction &f1)
{
    int numerator = f1.m_numerator * value;
   return Fraction(numerator, f1.m_denominator);
}
std::istream& operator>>(std::istream &in, Fraction &fraction)
{

    char cb;

    // Перезаписываем значения объекта f1
    in >> fraction.m_numerator;
    in >> cb; // игнорируем разделитель '/'
    in >> fraction.m_denominator;

    // Поскольку мы перезаписали существующий f1, то нам нужно повторно выполнить уменьшение дроби
    fraction.reduce();
    return in;
}
std::ostream& operator<<(std::ostream &out, const Fraction &fraction)
 {
      out << fraction.m_numerator << "/" << fraction.m_denominator;
      return out;
 }
int main()
{

    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    return 0;
}
