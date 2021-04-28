#include <iostream>
 #include <ctime> // раскомментируйте, если используете Code::Blocks
#include <random> // для std::random_device и std::mt19937

int getRandomNumber(int min, int max) {

  std::random_device device; // для получения зерна лучше чем от time(NULL)
  std::mt19937 mersenne(device()); // инициализируем Вихрь Мерсенна стартовым
                                   // числом

  std::uniform_int_distribution<> distribution(
      min, max); // Равномерное распределение [10, 20]

  int randomNumber = distribution(mersenne);
  // генерируем случайное число в заданом диапазоне

  return randomNumber;
  // возвращаем случайное число в заданом диапазоне
}

int main() {
  setlocale(LC_ALL, "");

  for (int count = 0; count < 200; ++count) {
    std::cout << getRandomNumber(-50000, 50000) << "\t";

    // Если вывели 5 чисел, то вставляем символ новой строки
    if ((count + 1) % 10 == 0)
      std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
