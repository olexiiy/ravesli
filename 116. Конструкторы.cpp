/* a) Напишите класс Ball, который должен иметь следующие две закрытые переменные-члены со значениями по умолчанию:
   m_color (Red);
   m_radius (20.0).
В Ball-е должны быть следующие конструкторы:
   для установления значения только для m_color;
   для установления значения только для m_radius;
   для установления значений и для m_radius, и для m_color;
   для установления значений, когда значения не предоставлены вообще.
Не используйте параметры по умолчанию для конструкторов. Напишите ещё одну функцию для вывода цвета (m_color) и радиуса 
(m_radius) шара (объекта класса Ball).
Следующий код функции main():
int main()
{
  Ball def;
  def.print();
 	Ball black("black");
	black.print();
	Ball thirty(30.0);
	thirty.print();
	Ball blackThirty("black", 30.0);
	blackThirty.print();
   return 0;
}
Должен производить следующий результат:
color: red, radius: 20
color: black, radius: 20
color: red, radius: 30
color: black, radius: 30

b) Теперь обновите ваш код из предыдущего задания с использованием конструкторов с параметрами по умолчанию. Постарайтесь
использовать как можно меньше конструкторов.
*/

#include <iostream>
#include <string>

class Ball
{
private:
    std::string  m_color;
    double m_radius;


public:

    // Конструктор с параметром radius (для color предоставлено значение по умолчанию)
Ball(double radius)
{
    m_color = "red";
    m_radius = radius;
}

    // Конструктор с параметрами color и radius
    // Обрабатываются случаи: не предоставлено никаких параметров, только color, color + radius
Ball(const std::string &color="red", double radius=20.0)
{
    m_color = color;
    m_radius = radius;
}   // Неявный конструктор не создастся, так как мы уже определили свой конструктор
    void print ()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << std::endl;
    }
};


int main()
{
        Ball def;
        def.print();

    Ball black("black");
    black.print();

    Ball thirty(30.0);
    thirty.print();

    Ball blackThirty("black", 30.0);
    blackThirty.print();

    return 0;
}
