

// ArrayInt.h

#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // для assert()

class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt():
        m_length(0), m_data(nullptr)
    {
    }

    ArrayInt(int length):
        m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // Здесь нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Функция reallocate изменяет размер массива. Все существующие элементы внутри массива будут уничтожены. Процесс быстрый
    void reallocate(int newLength)
    {
        // Удаляем все существующие элементы внутри массива
        erase();

        // Если наш массив должен быть пустым, то выполняем возврат здесь
        if (newLength <= 0)
            return;

        // Затем выделяем новые элементы
        m_data = new int[newLength];
        m_length = newLength;
    }

    // Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength)
    {
        // Если массив нужной длины, то выполняем return
        if (newLength == m_length)
            return;

        // Если нужно сделать массив пустым, то делаем это и затем выполняем return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Теперь мы можем предположить, что newLength состоит, по крайней мере, из одного элемента. Выполняется следующий алгоритм:
        // 1. Выделяем новый массив.
        // 2. Копируем элементы из существующего массива в наш, только что выделенный, массив.
        // 3. Уничтожаем старый массив и указываем m_data указывать на новый массив.

        // Выделяем новый массив
        int *data = new int[newLength];

        // Затем нам нужно разобраться с количеством копируемых элементов в новый массив
        // Мы хочем скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочерёдно копируем элементы
            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив.
        // Поскольку данные были динамически выделенные, то они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаём новый массив на один элемент больше старого массива
        int *data = new int[m_length+1];

        // Копируем все элементы аж до index-а
        for (int before=0; before < index; ++before)
            data [before] = m_data[before];

        // Вставляем наш новый элемент в наш новый массив
        data [index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый массив
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        // Проверка на корректность передаваемого индекса
        assert(index >= 0 && index < m_length);

        // Если это последний элемент массива, то делаем массив пустым и выполняем return
        if (m_length == 1)
        {
            erase();
            return;
        }

        // Cоздаём новый массив на один элемент меньше нашего старого массива
        int *data = new int[m_length-1];

        // Копируем все элементы аж до index-а
        for (int before=0; before  < index; ++before)
            data[before] = m_data[before];

        // Копируем все значения после удаляемого элемента
        for (int after=index+1; after < m_length; ++after )
            data[after-1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый массив
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    // Несколько дополнительных функций просто для удобства
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    int getLength() { return m_length; }
};
#endif // ARRAYINT_H



//main.cpp


#include <iostream>
#include "ArrayInt.h"

int main()
{
    // Объявляем массив с 10 элементами
    ArrayInt array(10);

    // Заполняем массив числами от 1 до 10
    for (int i=0; i<10; i++)
        array[i] = i+1;

    // Изменяем размер массива до 7 элементов
    array.resize(7);

    // Вставляем число 15 перед элементом с индексом 4
    array.insertBefore(15, 4);

    // Удаляем элемент с индексом 5
    array.remove(5);

    // Добавляем числа 35 и 50 в конец и в начало
    array.insertAtEnd(35);
    array.insertAtBeginning(50);

    // Выводим все элементы массива
    for (int j=0; j<array.getLength(); j++)
        std::cout << array[j] << " ";

    return 0;
}

