#include <iostream>
 #include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937

int getRandomNumber(long min, long max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	
	
	int randomNumber = static_cast<int>(rand() * fraction * (max - min + 1) + min); // генерируем случайное число в заданом диапазоне
	return randomNumber; // возвращаем случайное число в заданом диапазоне 
}

int main()
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна стартовым числом основаным не времени
	srand(static_cast<int>(mersenne()));  // в качестве стартового числа используем Вихрь Мерсенна случайным стартовым числом//
	rand();  //
	
	
	for (int count = 0; count < 200; ++count)
	{
		std::cout << getRandomNumber(-500, 500) << "\t";

		// Если вывели 5 чисел, то вставляем символ новой строки
		if ((count + 1) % 10 == 0)
			std::cout << "\n";
	}
	
}
