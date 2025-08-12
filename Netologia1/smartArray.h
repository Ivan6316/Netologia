#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <iostream>

class smart_array
{
private:
	size_t size__{};
	size_t capacity__{};
	int* data__;
public:
	// Выделение памяти
	smart_array(size_t size);

	// Добавление элемента
	void add_element(int number);

	// Получение элемента по индексу
	int get_element(int index) const;

	// Освобождение памяти
	~smart_array();
};


#endif // !SMART_ARRAY