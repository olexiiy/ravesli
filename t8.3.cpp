/*
Давайте создадим генератор случайных монстров.

a) Сначала создайте перечисление MonsterType со следующими типами монстров: Dragon, Goblin, Ogre, Orc, Skeleton, Troll,
Vampire и Zombie + добавьте MAX_MONSTER_TYPES, чтобы иметь возможность подсчитать общее количество всех перечислителей.

b) Теперь создайте класс Monster со следующими тремя атрибутами (переменными-членами): тип (MonsterType), имя (std::string)
и количество здоровья (int).

c) Перечисление MonsterType специфичное для Monster, поэтому переместите его во внутрь класса под спецификатор доступа public.

d) Создайте конструктор, который позволит инициализировать все переменные-члены класса.

e) Теперь нам нужно вывести информацию про нашего монстра. Для этого нужно конвертировать MonsterType в std::string. Добавьте 
функцию getTypeString(), которая будет выполнять конвертацию, и функцию вывода print().

Должна производить следующий результат:

Jack is the orc that has 90 health points.

f) Теперь мы уже можем создать сам генератор монстров. Для этого создайте статический класс MonsterGenerator и статический 
метод с именем generateMonster(), который будет возвращать случайного монстра. Пока что возвратом метода пускай будет 
анонимный объект: (Monster::Orc, "Jack", 90).

Должна производить следующий результат:

Jack is the orc that has 90 health points.

g) Теперь MonsterGenerator должен генерировать некоторые случайные атрибуты. Для этого нам понадобится генератор 
случайного числа.
Поскольку MonsterGenerator будет полагаться непосредственно на эту функцию, то поместите её во внутрь класса в 
качестве статического метода.

h) Теперь измените функцию generateMonster() для генерации случайного MonsterType (между 0 и Monster::MAX_MONSTER_TYPES-1) 
и случайного количества здоровья (от 1 до 100). Это должно быть просто. После того, как вы это сделаете, определите один 
статический фиксированный массив s_names размером 6 внутри функции generateMonster() и инициализируйте его 6 любыми именами 
на ваш выбор. Добавьте возможность выбора случайного имени из этого массива.

 Почему мы объявили массив s_names статическим?
 */


#include <iostream>
#include "timer.h"
/*Timer t1;
 std::cout << "elapsed: " << t1.elapsed() << '\n';*/
#include <string>
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937
using namespace std;

class Monster
{
public:
    enum MonsterType {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType m_type;
    std::string m_name;
    int m_health;
public:
    Monster(MonsterType type, std::string name, int health)
        : m_type(type), m_name(name), m_health(health) {}

    std::string getTypeString() const
    {
        switch (m_type)
        {
            case  Dragon:       return "dragon";
            case  Goblin:       return "goblin";
            case  Ogre:         return "ogre";
            case  Orc:          return "orc";
            case  Skeleton:     return "skeleton";
            case  Troll:        return "troll";
            case  Vampire:      return "vampire";
            case  Zombie:       return "zombie";
        default: return "uknown monster type";
        }
   }
    void print()
    {
        cout << m_name << " is the " << getTypeString() <<  " that has "
             << m_health <<  " health points." << endl;
    }
};

 class  MonsterGenerator
{
 public:
     // Генерируем случайное число между min и max (включительно)
     // Предполагается, что srand() уже был вызван
     static int getRandomNumber(int min, int max)
     {
         static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
         // Равномерно распределяем рандомное число в нашем диапазоне


         int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
         return randomNumber; // возвращаем случайное число в заданом диапазоне
     }
     static Monster generateMonster()
         {
         Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
         int health = getRandomNumber(1, 100);

         static std::string s_names[10]{ "John", "Brad", "Alex", "Thor", "Hulk",
                                         "Asnee", "Dig", "Muse","Oleg", "Keeper"};
           return Monster(type, s_names[getRandomNumber(0, 9)], health);
         }
};
int main()
{
   std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
   srand(static_cast<int>(mersenne()));  // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
   rand();
   for (int var = 0; var < 100; ++var) {
       Monster mvar = MonsterGenerator::generateMonster();
       mvar.print();

   }

    return 0;
}
