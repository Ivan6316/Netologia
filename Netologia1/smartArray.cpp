#include "smartArray.h"

smart_array::smart_array(size_t size) : data__(new int[size]), size__(0), capacity__(size) {}

smart_array::~smart_array() { delete[] data__; }

void smart_array::add_element(int number)
{
	if (size__ >= capacity__)
	{
		// ����������� ������ � 2 ����
		size_t newCapacity{ capacity__ * 2 };
		int* newData = new int[newCapacity];

		// �������� ��������
		for (size_t index{}; index < size__; ++index)
		{
			newData[index] = data__[index];
		}

		// ����������� ������ ������
		delete[] data__;

		// ��������� ������� � ������
		data__ = newData;
		capacity__ = newCapacity;
	}
	data__[size__++] = number;
}

int smart_array::get_element(int index) const
{
	// �������� �� ���������� ������
	if (index < 0 || index >= size__)
	{
		// ����������� ������
		throw std::out_of_range("Invalid index");
	}
	return data__[index];
}