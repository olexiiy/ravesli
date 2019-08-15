/*
Создайте родительский класс Fruit, который имеет два закрытых члена: name (std::string) и color (std::string). 
Создайте класс Apple, который наследует свойства Fruit. У Apple должен быть дополнительный закрытый член: fiber (тип double).
Создайте класс Banana, который также наследует класс Fruit. Banana не имеет дополнительных членов.
Подсказка: Поскольку a и b являются const, то убедитесь, что ваши параметры и функции соответствуют const.
*/


#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;
public:
    Fruit(std::string name = "", std::string color = "") : m_name(name), m_color(color) {}
    std::string getName() const { return m_name; }
    std::string getColor() const { return m_color; }

};

class Apple : public Fruit
{
private:
    double m_fiber;

public:
    Apple(std::string name, std::string color, double fiber)
        :Fruit(name, color), m_fiber(fiber)
    {
    }

    double getFiber() const { return m_fiber; }

    friend std::ostream& operator<<(std::ostream &out, const Apple &a)
    {
        out << "Apple (" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ")\n";
        return out;
    }
};

class Banana : public Fruit
{
public:
    Banana(std::string name, std::string color)
        :Fruit(name, color)
    {
    }

    friend std::ostream& operator<<(std::ostream &out, const Banana &b)
    {
        out << "Banana (" << b.getName() << ", " << b.getColor() << ")\n";
        return out;
    }

};

int main()
{
       const Apple a("Red delicious", "red", 7.3);
        std::cout << a;

        const Banana b("Cavendish", "yellow");
        std::cout << b;

    return 0;
}
