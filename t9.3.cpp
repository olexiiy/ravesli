/*
Напишите свой собственный класс-массив целых чисел IntArray (не используйте std::array или std::vector). Пользователи должны
передавать размер массива при создании объекта этого класса, а сам массив (переменная-член) должен выделяться динамически.
Используйте стейтменты assert для проверки передаваемых значений и свой конструктор копирования и перегрузку оператора 
присваивания, если это необходимо.
*/

class IntArray
{
private:
    int m_length = 0;
    int *m_array = nullptr;

public:
    IntArray(int length):
        m_length(length)
    {
        assert(length > 0 && "IntArray length should be a positive integer");

        m_array = new int[m_length] { 0 };
    }

    // Конструктор копирования, который выполняет глубокое копирование
    IntArray(const IntArray &array):
        m_length(array.m_length)
    {
        // Выделяем новый массив
        m_array = new int[m_length];

        // Копируем элементы из исходного массива в наш, только что выделенный, массив
        for (int count = 0; count < array.m_length; ++count)
            m_array[count] = array.m_array[count];
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    // Функция перегрузки оператора <<
    friend std::ostream& operator<<(std::ostream &out, const IntArray &array)
    {
        for (int count = 0; count < array.m_length; ++count)
        {
            out << array.m_array[count] << ' ';
        }
        return out;
    }

    int& operator[] (const int index)
    {
        assert(index >= 0);
        assert(index < m_length);
        return m_array[index];
    }

    // Перегрузка оператора присваивания с выполнением глубокого копирования
    IntArray& operator= (const IntArray &array)
    {
        // Проверка на самоприсваивание
        if (this == &array)
            return *this;

        // Если массив уже существует, то удаляем его, дабы не произошла утечка памяти
        delete[] m_array;

        m_length = array.m_length;

        // Выделяем новый массив
        m_array = new int[m_length];

        // Копируем элементы из исходного массива в наш, только что выделенный, массив
        for (int count = 0; count < array.m_length; ++count)
            m_array[count] = array.m_array[count];

        return *this;
    }

};

IntArray fillArray()
{
    IntArray a(6);
    a[0] = 6;
    a[1] = 7;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
        a[5] = 8;

    return a;
}

int main()
{
    IntArray a = fillArray();

    // Если у вас здесь получается какая-то чепуха, то, скорее всего, вы забыли выполнить глубокое копирование в вашем конструкторе копирования
    std::cout << a << '\n';

    IntArray b(1);
    a = a;
    b = a;

    // Если у вас здесь получается какая-то чепуха, то, скорее всего, вы забыли выполнить глубокое копирование в своей функции перегрузки оператора присваивания,
    // либо забыли о проверке на самоприсваивание
    std::cout << b << '\n';

    return 0;
}
