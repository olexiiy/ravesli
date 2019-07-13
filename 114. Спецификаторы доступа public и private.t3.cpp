/*
Теперь попробуем что-то посложнее. Напишите класс, который реализует функционал стека. Класс Stack должен иметь:
   Открытый целочисленный фиксированный массив длиной 10.
   Открытое целочисленное значение для отслеживания длины стека.
   Открытый метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0.
   Открытый метод с именем push(), который будет добавлять значение в стек. Метод push() должен возвращать значение false,
   если массив уже заполнен, в противном случае — true.
   Открытый метод с именем pop() для возврата значений из стека. Если в стеке нет значений, то должен выводиться стейтмент 
   assert.
   Открытый метод с именем print(), который будет выводить все значения стека.
   Должен производить следующий результат:

( )
( 3 7 5 )
( 3 7 )
( )
*/

#include <iostream>
#include <cassert>
class Stack
{
    public:
    int m_array[10] {};

    int m_quantity {};

    void reset()
    {
        m_quantity = 0;
        for (int index {}; index < 10; index++)
        m_array[index]=0;
    }

     bool push (int x)
    {
        if (x == 10)
            return false;
        m_array[m_quantity++] = x; // присваиваем следующему свободному элементу значение value, а затем увеличиваем m_next
        return true;
    }

     int pop()
     {
         // Если элементов в стеке нет, то выводим стейтмент assert
         assert (m_quantity > 0 && " you try to delete empty stack");
                 // m_next указывает на следующий свободный элемент, поэтому последний элемент со значением - это m_next-1
                 // Мы хотим сделать следующее:
                 // int val = m_array[m_next-1]; // получаем последний элемент со значением
                 // --m_next; // m_next теперь на единицу меньше, так как мы только что вытянули верхний элемент стека
                 // return val; // возвращаем элемент
                 // Весь код выше можно заменить следующей (одной) строчкой кода:
         return m_array[--m_quantity];
     }

     void print()
     {
         std::cout << "( ";
         for (int i = 0; i < m_quantity; ++i)
             std::cout << m_array[i] << ' ';
         std::cout << ")\n";
     }
};

int main()
{
    Stack stack;
    stack.reset();
    stack.pop();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}
