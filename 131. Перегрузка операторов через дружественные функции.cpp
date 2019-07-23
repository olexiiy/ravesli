

#include <iostream>

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
};
void Fraction::print ()
{
std::cout << m_numerator << "/" << m_denominator << "\n";
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

int main()
{

    Fraction f1(3, 4);
    f1.print();

    Fraction f2(2, 7);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 3;
    f4.print();

    Fraction f5 = 3 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
    return 0;
}
