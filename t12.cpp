/*
Реализуйте класс Pair, который позволяет пользователю использовать разные типы данных в передаваемых парах. 

Напишите шаблон класса StringValuePair, в котором первое значение всегда является типа string, а второе может быть
любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair (в котором первый параметр
— std::string, а второй — «любой тип данных»). 

*/

#include <iostream>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        //#include <iostream>
#include <string>

template <class T1, class T2> // size является параметром non-type шаблона
class Pair
{
private:
    T1 m_first {};
    T2 m_second{};
public:
    Pair(const T1& first,const T2& second) : m_first(first), m_second(second)  {}
    T1& first()
    {
        return  this->m_first;
    }
    const T1& first() const
    {
        return  this->m_first;
    }
    T2& second()
    {
        return  this->m_second;
    }
    const T2& second() const
    {
        return  this->m_second;
    }
};

template <typename T2>
         class StringValuePair : public Pair<std::string, T2> 
{
         public:
             StringValuePair(const std::string& first,const T2& second) : 
                 Pair<std::string, T2>(first, second){}
             
        };


int main()
{
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    return 0;
}
