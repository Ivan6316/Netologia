#include <iostream>
#include <vector>
#include <algorithm>

// Вывод вектора
void printVector(std::vector<int> vec);

int main()
{
	// Подключение Русского языка
	setlocale(LC_ALL, "rus");

	std::vector<int> numbers = { 1, 1, 2, 5, 6, 1, 2, 4 };

	std::cout << "Вектор до удаления дубликатов: ";
	printVector(numbers);

	// Сортируем вектор
	std::sort(numbers.begin(), numbers.end());
	// Удаляем повторяющееся последовательные элементы
	auto it{ std::unique(numbers.begin(), numbers.end()) };
	numbers.erase(it, numbers.end());

	std::cout << "Вектор после удаления дубликатов: ";
	printVector(numbers);


	return EXIT_SUCCESS;
}

void printVector(std::vector<int> vec)
{
	for (const int& num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}