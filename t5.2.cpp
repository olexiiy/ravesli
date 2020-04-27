/*
Напишите программу-игру типа Hi-Lo. Во-первых, ваша программа должна выбрать случайное целое число в диапазоне 
от 1 до 100. Пользователю даётся 7 попыток, чтобы угадать это число. Если пользователь не угадывает число, то
программа должна подсказывать, была ли его догадка слишком большой или слишком маленькой. Если пользователь угадывает 
число, то программа должна сообщить, что всё верно, вы выиграли. Если же у пользователя кончились попытки, и он не
угадал число, то программа должна сообщить ему, что он проиграл и показать правильный результат. В конце игры 
программа должна спросить у пользователя, не хочет ли он поиграть ещё раз. Если пользователь не ведёт ни y, ни n (а
что-то другое), то программа должна спросить его ещё раз.
*/
#include <ctime> // раскомментируйте, если используете Code::Blocks
#include <iostream>
#include <random> // для std::random_device и std::mt19937

int getRandomNumber(long min, long max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне

    int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
    return randomNumber; // возвращаем случайное число в заданом диапазоне
}

int getInteger()
{

    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        int x;
        std::cin >> x;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } else {
            std::cin.ignore(32767, '\n'); // удаляем лишние значения

            return x;
        }
    }
}

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

bool theGame(int randomNumber)
{
    for (int count = 1; count <= 7; ++count) {
        std::cout << "Guess #" << count << ": ";
        int possible = getInteger();
        if (possible == randomNumber) {

            return true;

        } else if (possible > randomNumber) {
            std::cout << "Your guess is too high." << std::endl;

            if (count == 7) {
                std::cout << "You lose";
                return false;
            }
        } else if (possible < randomNumber) {
            std::cout << "Your guess is too low." << std::endl;
            if (count == 7) {
                std::cout << "You lose" << std::endl;
                return false;
            }
        };
    }
}

int main()
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
    srand(static_cast<int>(mersenne())); // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
    rand();

    int randomNumber = getRandomNumber(1, 111);

    do {

        //        std::cout << randomNumber << std::endl;
        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is." << std::endl;
        bool won = theGame(randomNumber);
        if (won == true)
            std::cout << "Correct! You win!" << std::endl;
        else

            std::cout << "Sorry, you lose. The correct number was " << randomNumber << std::endl;

    } while (playAgain());

    std::cout << "thank you for the game";

    return 0;
}

