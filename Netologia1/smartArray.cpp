#include "smartArray.h"

smart_array::smart_array(size_t size) : data__(new int[size]), size__(0), capacity__(size) {}

smart_array::~smart_array() { delete[] data__; }

void smart_array::add_element(int number)
{
	if (size__ >= capacity__)
	{
		// Увеличиваем массив в 2 раза
		size_t newCapacity{ capacity__ * 2 };
		int* newData = new int[newCapacity];

		// Копируем элементы
		for (size_t index{}; index < size__; ++index)
		{
			newData[index] = data__[index];
		}

		// Освобождаем старую память
		delete[] data__;

		// Обновляем ёмкость и память
		data__ = newData;
		capacity__ = newCapacity;
	}
	data__[size__++] = number;
}

int smart_array::get_element(int index) const
{
	// Проверка на корректный индекс
	if (index < 0 || index >= size__)
	{
		// Выбрасываем ошибку
		throw std::out_of_range("Invalid index");
	}
	return data__[index];
}