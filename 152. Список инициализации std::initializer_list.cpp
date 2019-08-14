 //перегрузка оператора присваивания, который будет принимать список инициализации

#include <iostream>
#include <cassert> // для assert()
#include <initializer_list> // для std::initializer_list

class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() :
		m_length(0), m_data(nullptr)
	{
	}

	ArrayInt(int length) :
		m_length(length)
	{
		m_data = new int[length];
	}

	ArrayInt(const std::initializer_list<int>& list) : // позволяем инициализацию ArrayInt через список инициализации
		ArrayInt(list.size()) // используем концепцию делегирования конструкторов для создания начального массива, в который будет выполняться копирование элементов
	{
		// Инициализация нашего начального массива значениями из списка инициализации
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~ArrayInt()
	{
		delete[] m_data;
		// Нам не нужно здесь присваивать значение null для m_data или выполнять m_length = 0, так как объект будет уничтожен сразу же после выполнения этой функции
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int  getLength() { return m_length; }

	ArrayInt& operator=(const std::initializer_list<int>& list)
	{
		// Если новый список имеет другой размер, то перевыделяем его
		if (list.size() != static_cast<size_t>(m_length))
		{
			// Удаляем все существующие элементы
			delete[] m_data;

			// Перевыделяем массив
			m_length = list.size();
			m_data = new int[m_length];
		}

		// Теперь инициализируем наш массив значениями из списка
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}

		return *this;
	}
};


int main()
{
	ArrayInt array{ 7, 6, 5, 4, 3, 2, 1 }; // список инициализации
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 4, 9, 12, 15, 17, 19, 21 };

	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	return 0;
}
