#include <chrono>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <future>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <thread>

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


bool playAgain()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "Would you like to play again (y/n)?";
        char answer;
        std::cin >> answer;

        // Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

        std::cin.ignore(32767, '\n'); // удаляем лишний балласт

        // Выполняем проверку пользовательского ввода
        if (answer == 'y')
            return true; // возвращаем обратно в caller
        else if (answer == 'n')
            return false; // возвращаем обратно в caller
        else // в противном случае, сообщаем пользователю что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}

char getGuess()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "\nInput 'h' for too high or 'l' for too low or 'y' for if correct" << std::endl;
        char sm;

        std::cin >> sm;

        std::cin.ignore(32767, '\n');
        // Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

        switch (sm) {
        case 'h':
        case 'H':
        case 'l':
        case 'L':
        case 'y':
        case 'Y':
            return sm; // возвращаем обратно в caller
        default:
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    }
}

int binarySearch(int min, int max)
{
#ifdef DEBUG
    int counter = 0;
#endif
    const int guesses = 7; // у поI (computer)льзователя есть 7 попыток

    std::cout << "I have " << guesses << std::endl;
    int count = 0;
    while (min <= max) {
        ++count;

        std::cout << "Guess #" << count;
#ifdef DEBUG
        ++counter;
#endif

        // Итеративная реализация
        int midpoint
            = min + ((max - min) / 2); // такой способ вычисления середины массива избегает вероятность возникновения переполнения

        std::cout << "  I (computer), maybe you maked up  " << midpoint;

        char guess = getGuess();

        if (guess == 'h' || guess == 'h') {
            // Если array[midpoint] > target, то тогда понимаем, что искомое число не находится в правой половине массива
            // Мы можем использовать midpoint - 1 в качестве индекса максимальной границы, так как в следующей итерации этот индекс вычислять не нужно
            max = midpoint - 1;
        } else if (guess == 'l' || guess == 'L') {
            // Если array[midpoint] < target, то тогда понимаем, что искомое число не находится в левой половине массива
            // Мы можем использовать midpoint + 1 в качестве индекса минимальной границы, так как в следующей итерации этот индекс вычислять не нужно
            min = midpoint + 1;

        } else if (guess == 'Y' || guess == 'y')
            return midpoint;
    }

    return 0;
}
enum min_max {
    min = 1,
    max = 111
};

int main()
{
    Timer timer;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    do {
        cout << "\tWelcome to Guess My Number" << std::endl
             << std::endl;

        int result = binarySearch(min_max::min, min_max::max);

        if (result)
            std::cout << "Your number is " << result << std::endl;
        else
            std::cout << "Don't try to lying for me" << std::endl;

    } while (playAgain());
    std::cout << "Time elapsed: " << timer.elapsed() << '\n';
    return EXIT_SUCCESS;
}
