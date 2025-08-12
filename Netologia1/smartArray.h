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
	// ��������� ������
	smart_array(size_t size);

	// ���������� ��������
	void add_element(int number);

	// ��������� �������� �� �������
	int get_element(int index) const;

	// ������������ ������
	~smart_array();
};


#endif // !SMART_ARRAY