/*
цикл for
программа имитации мячика, падающего с башни.

чтобы мячик падал столько секунд, сколько необходимо, пока не достигнет земли.
*/



#include <iostream>


int main()
{
	std::cout << "Enter the height of the tower in meters: ";
	int height{};
	std::cin >> height;
	double distanceFallen{};
	for (int count{}; (static_cast<double>(height) - distanceFallen) > 0; count++)
	{
		distanceFallen = 9.8 * count * count / 2;
		double currentHeight = height - distanceFallen;
		if ((static_cast<double>(height) - distanceFallen) > 0)
		{
			std::cout << "At " << count << " seconds, the ball is at height:\t" << currentHeight <<
				" meters\n";
		}
		else
			std::cout << "At " << count << " seconds, the ball is on the ground.\n";
	}

	double times = sqrt((2 * static_cast<double>(height)) / 9.8);

	std::cout << "the ball need " << times << " seconds, to fall on the ground.\n";

	system("pause");

	return 0;
}
