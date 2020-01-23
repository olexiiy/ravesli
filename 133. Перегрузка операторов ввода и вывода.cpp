#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	
	
	
public:
	Fraction(const int numerator = 0, const int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
	{
		reduce();
	};

	static int nod(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	}
	Fraction& reduce()
	{
		int nod = Fraction::nod(m_numerator, m_denominator);
		m_numerator /= nod;
		m_denominator /= nod;

		return *this;
	}
	
	
	friend std::ostream& operator<< (std::ostream& out, const Fraction& f);
	friend std::istream& operator>> (std::istream& in,  Fraction& f);

	
	// Выполняем умножение через дружественную функцию
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, const int value);
	friend Fraction operator*(const int value, const Fraction& f2);
	
	const Fraction& print() const
	{
		std::cout << m_numerator << "/" << m_denominator << std::endl;
		return *this;
	}

};

 std::ostream& operator<< (std::ostream& out, const Fraction& f)
 {
	 out << f.m_numerator << "/" << f.m_denominator;
	 return out;
 }
 std::istream& operator>> (std::istream& in,  Fraction& f)
 {
	 char c;
 	
	 in >> f.m_numerator;
	 in >> c; // игнорируем разделитель '/'
	 in >> f.m_denominator;

	 // Поскольку мы перезаписали существующий f1, то нам нужно повторно выполнить уменьшение дроби
	 f.reduce();
 	
	 return in;
 }


// Примечание: Эта функция не является методом класса!
Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	// Используем конструктор Dollars и operator+(int, int)
	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction& f1, const int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator );
}

 Fraction operator*(const int value, const Fraction& f2)
{
	 return f2 * value;
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
