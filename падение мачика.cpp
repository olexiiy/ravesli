/*
цикл for
программа имитации мячика, падающего с башни.

чтобы мячик падал столько секунд, сколько необходимо, пока не достигнет земли.
*/


/*
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace myConstants
{
    const double gravity(9.8);
}
#endif
*/

#include <iostream>
#include "constants.h"

int getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
       
        int a;
        std::cin >> a;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // удаляем лишние значения

            return a;
        }
    }
}


// Получаем начальную высоту от пользователя и возвращаем её
int getInitialHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    int initialHeight{ getValue() };
    return initialHeight;
}

// Возвращаем расстояние от земли после "..." секунд падения
double calculateHeight(double initialHeight, int seconds)
{
    // Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
    double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
    double currentHeight = initialHeight - distanceFallen;

    return currentHeight;
}

// Выводим высоту, на которой находится мячик после каждой секунды падения
void printHeight(const double& height, const int& seconds)
{
    if (height > 0.0)
    {
        std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
            " meters\n";
    }
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(const double& initialHeight, const int& seconds)
{
    double height = calculateHeight(initialHeight, seconds);
    printHeight(height, seconds);
}

int main()
{
    const int height{ getInitialHeight() };
    
    double distanceFallen{};
    for (int seconds{}; (static_cast<double>(height) - distanceFallen) > 0; seconds++)
    {
        distanceFallen = myConstants::gravity * seconds * seconds / 2;
        double currentHeight = height - distanceFallen;
        printHeight(currentHeight, seconds);
    }

    double times = sqrt((2 * static_cast<double>(height) / myConstants::gravity));

    std::cout << "the ball need " << times << " seconds, to fall on the ground.\n";

    return 0;
}

