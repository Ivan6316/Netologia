#include <iostream>
#include <vector>

template<typename T>
T squaring(T a);

template<>
std::vector<int> squaring(std::vector<int> vector);

int main()
{
	int number{ 4 };
	double aNumberWithADot{ 2.5 };
	std::vector<int> vector{ 1, 2, 3, 4, 5 };

	// Вывод ответов
	std::cout << squaring(number) << std::endl;
	std::cout << squaring(aNumberWithADot) << std::endl;
	for (int num : squaring(vector))
	{
		std::cout << num << " ";
	}


	return EXIT_SUCCESS;
}

template<typename T>
T squaring(T a)
{
	return a * a;
}

template<>
std::vector<int> squaring(std::vector<int> vector)
{
	// Вектор ответов
	std::vector<int> answers;
	for (int num : vector)
	{
		answers.push_back(num * num);
	}

	return answers;
}