/*
Напишите класс Average, который будет вычислять среднее значение всех передаваемых ему целых чисел. Используйте два члена: 
первый должен быть типа int32_t и использоваться для вычисления суммы всех передаваемых чисел. Второй должен быть типа int8_t 
и использоваться для вычисления количества передаваемых чисел. Чтобы найти среднее значение нужно разделить сумму на количество.

*/

#include <iostream>

class Average
{
private:
    int32_t m_sum = 0;
    int m_length = 0;

public:
    Average(){}
friend std::ostream& operator<<(std::ostream &out, const Average &average);
   Average& operator+=(int value);

};

Average& Average::operator+=(int value)
{
    m_sum += value;
    ++m_length;
    return *this;
}
std::ostream& operator<<(std::ostream &out, const Average &average)
{
    out << static_cast<double>(average.m_sum) / average.m_length;
    return out;

}
int main()
{
    Average avg;

    avg += 5;
    std::cout << avg << '\n'; // 5 / 1 = 5

    avg += 9;
    std::cout << avg << '\n'; // (5 + 9) / 2 = 7

    avg += 19;
    std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

    avg += -9;
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

    (avg += 7) += 11; // выполнение цепочки операций
    std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

    Average copy = avg;
    std::cout << copy << '\n';

    return 0;
}
