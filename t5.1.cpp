/*/*
цикл do while
программа имитации мячика, падающего с башни.
чтобы мячик падал столько секунд, сколько необходимо, пока не достигнет земли.
*/



/*  #include "constants.h"
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

// Получаем начальную высоту от пользователя и возвращаем её
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
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
void printHeight(double height, int seconds)
{
	std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
	" meters\n";
	 
}

void calculateAndPrintHeight(double initialHeight, int seconds)
{
	double height = calculateHeight(initialHeight, seconds);
	printHeight(height, seconds);
}

int main()
{
	const double initialHeight = getInitialHeight();

	int seconds = 0;
	double height;

	do
	{
		height = calculateHeight(initialHeight, seconds);
		if(height > 0.0) {
		printHeight(height, seconds); }
		else{
		s std::cout << "At " << sqrt(2*initialHeight/gravity) << " seconds, the ball is on the ground.\n";}
		++seconds;
	} while (height > 0.0);

	return 0;
}
