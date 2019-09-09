/*
Напишите класс Fraction, конструктор которого принимает числитель и знаменатель. Если пользователь передал в качестве 
знаменателя 0, то выбрасывайте исключение типа std::runtime_error (которое находится в заголовочном файле stdexcept).
В функции main() попросите пользователя ввести два целых числа. Если числа корректные, то выводите создаваемый объект
класса Fraction. Если же числа недопустимые, то вы должны обрабатывать исключение типа std::exception и сообщить 
пользователю, что он ввёл некорректные данные.

Подсказка: std::runtime_error является дочерним классу-исключению std::exception, поэтому у вас должен быть только один
блок catch.

Пример выполнения программы:

Enter the numerator: 7
Enter the denominator: 0
Your fraction has an invalid denominator.
*/

#include <iostream>
 #include <stdexcept>
bool again()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "Would you like to input again (y/n)?";
        char answer;
        std::cin >> answer;

        // Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

        std::cin.ignore(32767, '\n'); // удаляем лишний балласт

        // Выполняем проверку пользовательского ввода
        if (answer == 'y' )
            return true; // возвращаем обратно в caller
        else if (answer == 'n')
            return false; // возвращаем обратно в caller
        else // в противном случае, сообщаем пользователю что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}
class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator=0, int denominator=1):
        m_numerator(numerator), m_denominator(denominator)
    {
        if (m_denominator == 0)
            throw std::runtime_error("Invalid denominator");
        // Мы поместили reduce() в конструктор, чтобы убедиться, что все дроби, которые у нас есть, будут уменьшены!
        // Все дроби, которые перезаписаны, должны быть повторно уменьшены
        reduce();
    }

    // Делаем функцию nod статической, чтобы она могла быть частью класса Fraction и при этом, для её использования, нам не требовалось бы создавать объект класса Fraction
    static int nod(int a, int b)
    {
        return b == 0 ? a : nod(b, a % b);
    }

    void reduce()
    {
        int nod = Fraction::nod(m_numerator, m_denominator);
        m_numerator /= nod;
        m_denominator /= nod;
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, int value);
    friend Fraction operator*(int value, const Fraction &f1);
    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
    friend std::istream& operator>>(std::istream& in, Fraction &f1);
    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
Fraction operator*(const Fraction &f1, int value)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}
Fraction operator*(int value, const Fraction &f1)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}
std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}
std::istream& operator>>(std::istream& in, Fraction &f1)
{
    char c;

    // Перезаписываем значения объекта f1
    in >> f1.m_numerator;
    in >> c; // игнорируем разделитель '/'
    in >> f1.m_denominator;

    // Поскольку мы перезаписали существующий f1, то нам нужно повторно выполнить уменьшение дроби
    f1.reduce();

    return in;
}

int main()
{
    do
        {
            std::cout << "Enter the numerator: ";
            int numerator{};
            std::cin >> numerator;
            std::cout << "Enter the denominator: ";
            int denominator{};
            std::cin >> denominator;
            try
            {
                Fraction fraction (numerator, denominator);
                std::cout << "Your fraction is: " << fraction << '\n';
            }
            catch (std::exception&)
                {
                    std::cout << "Your fraction has an invalid denominator.\n";
                }


        }while (again());
}
