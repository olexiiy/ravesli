#include <chrono>

#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <iostream>
#include <mutex>
#include <queue>
#include <random> // для std::random_device и std::mt19937
#include <thread>
#include <vector>
//using namespace std;

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
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

const int32_t MAX_COUNTER = 50;

std::queue<int32_t> collection;
std::mutex simple_mutex;
int32_t counter;

int getRandomNumber(long min, long max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне // возвращаем случайное число в заданом диапазоне
}
void prepare_data()
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
    srand(static_cast<int>(mersenne())); // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
    rand(); // сбрасываем первый результат

    int32_t value {};
    std::thread th([&value]() {
        value = getRandomNumber(100, 1000);
    });
    std::unique_lock<std::mutex> lock(simple_mutex);

    collection.push(value);
    std::this_thread::sleep_for(std::chrono::milliseconds(value));
    lock.unlock();

    ++counter;

    if (counter >= MAX_COUNTER) {
        return;
    }

    prepare_data();
}

void extract_data()
{

    std::unique_lock<std::mutex> lock(simple_mutex);

    std::cout << "Value: " << collection.back() << std::endl;

    collection.pop();
    lock.unlock();

    if (counter >= MAX_COUNTER) {
        return;
    }

    extract_data();
}
int32_t main(const int32_t argc, const char* argv[])
{
    Timer t;
    std::thread prepare_thread(prepare_data);
    std::thread extract_thread(extract_data);

    prepare_thread.join();
    extract_thread.join();

    std::cout << "Time elapsed: " << t.elapsed() << '\n';
    return EXIT_SUCCESS;
}
