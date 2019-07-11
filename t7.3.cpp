//Лучшим алгоритмом определения того, существует ли значение в отсортированном массиве или нет, является бинарный поиск.

#include <iostream>

// array - это массив, в котором мы проводим поиски
// target - это искомое значение
// min - это индекс минимальной границы массива, в котором мы осуществляем поиск
// max - это индекс максимальной границы массива, в котором мы осуществляем поиск
// binarySearch() должен возвращать индекс искомого значения, если оно обнаружено. В противном случае, возвращаем -1
int binarySearch(int *array, int target, int min, int max)
{

    while (min <= max)
    {
       int  mid = min + ((max - min)/2);
        if(array[mid] > target)
        {
            max = mid - 1;
        }
        else if(array[mid] < target)
        {
            min = mid + 1;
        }
        else
            return mid;

    }
    return -1;
}

int binarySearch1(int *array, int target, int min, int max)
{
        if (min > max)
        return -1;
       int mid = min + ((max - min)/2);
        if(array[mid] > target)
        {
            return binarySearch1(array,  target,  min, mid - 1);
        }
        else if(array[mid] < target)
        {
            return binarySearch1(array, target, mid + 1,  max);
        }
        else
            return mid;

}




int main()
{
    int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    int index = binarySearch(array, x, 0, 14);

     std::cout << "Iteration method" << std::endl;

    if (array[index] == x)
        std::cout << "Good! Your value " << x << " is on position "<< index << " in array!\n";
    else
        std::cout << "Fail! Your value " << x << " isn't in array!\n";

    int index1 = binarySearch1(array, x, 0, 14);

    std::cout << "Recursive method" << std::endl;

   if (array[index1] == x)
       std::cout << "Good! Your value " << x << " is on position "<< index1 << " in array!\n";
   else
       std::cout << "Fail! Your value " << x << " isn't in array!\n";
    return 0;
}
