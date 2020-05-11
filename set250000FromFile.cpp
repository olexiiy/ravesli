#include <chrono>
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random> // для std::random_device и std::mt19937
#include <set>
#include <string>

class Timer {
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer()
        : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count() * 1000;
    }
};

int getRandomNumber(long min, long max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне

    int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
    return randomNumber; // возвращаем случайное число в заданом диапазоне
}

int main()
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным на времени
    srand(static_cast<int>(mersenne())); // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
    rand(); // сбрасываем первый результат

    Timer t;

    std::ifstream in("input.txt");
    int element_count;
    in >> element_count;

    std::set<int> elements;
    for (int i = 0; i < element_count; ++i) {
        int x;
        in >> x;
        elements.insert(x);
    }
    std::cerr << std::endl
              << t.elapsed() << " milliseconds" << std::endl;
    int query_count;
    in >> query_count;

    int total_found = 0;
    for (int i = 0; i < query_count; ++i) {
        int x;
        in >> x;
        if (elements.find(x) != elements.end()) {
            ++total_found;
        }
    }

    std::cout << total_found << std::endl;

    std::cerr << std::endl
              << t.elapsed() << " milliseconds" << std::endl;
    //    std::cout << std::setw(5) << getRandomNumber(1, 99) << " \n"; // из заданого диапазона
}
