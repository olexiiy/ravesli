/*
Представьте, что вы пишите игру, в которой игрок может иметь 3 типа предметов: зелье здоровья, факелы и стрелы. 
Создайте перечисление с этими типами предметов и фиксированный массив для хранения количества каждого типа предмета, 
который имеет при себе игрок (используйте стандартные фиксированные массивы, а не std::array). У вашего игрока должны 
быть при себе 3 зелья здоровья, 6 факелов и 12 стрел. Напишите функцию countTotalItems(), которая возвращает общее 
количество элементов, которые есть в игрока. В функции main() выведите результат работы функции countTotalItems().
*/


#include <iostream>
enum BackPackage
{
    health,
    fakels,
    arrows,
    all,
};

int countTotalItems(int *array)
{
    int sum {};
    for (int index = 0; index < BackPackage::all; ++index)
        sum += array[index];
    return sum;
}

int main()
{
    int array[BackPackage::all] {3, 6, 12};

    std::cout << "The player has " << countTotalItems(array) << " items in total." << std::endl;

    return 0;
}
