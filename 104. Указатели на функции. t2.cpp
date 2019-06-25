/*
a) Создайте структуру с именем arithmeticStruct, которая имеет два члена: математический оператор типа char и 
указатель на функцию arithmeticFcn.
b) Создайте статический глобальный массив arithmeticArray, используя структуру arithmeticStruct, который будет 
инициализирован каждой из четырёх математических операций.
c) Измените getArithmeticFcn для выполнения цикла по массиву и возврата соответствующего указателя на функцию.
Подсказка: Используйте цикл foreach.
*/
// программа «Калькулятор», но уже с полным механизмом обработки/проверки ошибок
#include <iostream>
//#include <functional>  // Использование std::function в C++11, альтернативный способ определения и хранения указателей на функции

bool arithmeticAgain()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "Would you like to calc again (y/n)?";
        char answer;
        std::cin >> answer;

        // Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

        std::cin.ignore(32767, '\n'); // удаляем лишний балласт

        // Выполняем проверку пользовательского ввода
        if (answer == 'y' )
            return true; // возвращаем обратно в caller
        else if (answer == 'n')
            return false; // возвращаем обратно в caller
        else // в противном случае, сообщаем пользователю что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}

double getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "Enter a double value: ";
        double a;
        std::cin >> a;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767,'\n'); // удаляем лишние значения

            return a;
        }
    }
}

char getOperator()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        std::cin >> sm;

        // Переменные типа char могут принимать любые символы из пользовательского ввода, поэтому нам не стоит беспокоиться по поводу возникновения неудачного извлечения

        std::cin.ignore(32767,'\n'); // удаляем лишний балласт

        // Выполняем проверку пользовательского ввода
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/')
            return sm; // возвращаем обратно в caller
        else // в противном случае, сообщаем пользователю что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

typedef double (*arithmeticFcn)(double, double); // std::function<double(double, double)> arithmeticFcn

struct arithmeticStruct
{
    char op;
    arithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[] {
    { '+', add },
    { '-', subtract },
    { '*', multiply },
    { '/', divide }
};

arithmeticFcn getArithmeticFcn(char op)
{
    for (auto &arith : arithmeticArray)
    {
        if (arith.op == op)
            return arith.fcn;
    }

    return add; // функцией по умолчанию будет add
}

int main()
{
    do
    {
    double a = getValue();
    char op = getOperator();
    double b = getValue();

    arithmeticFcn fcn = getArithmeticFcn(op);
    std::cout << a << ' ' << op << ' ' << b << " = " << fcn(a, b) << '\n';
    }while (arithmeticAgain());

    std::cout << "GOODBYE" << std::endl;
    return 0;
}




