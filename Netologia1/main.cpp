#include <iostream>
#include <vector>

template<typename T>
void squaring(T a);

template<>
void squaring(std::vector<int> vector);

int main()
{
	int number{ 4 };
	double aNumberWithADot{ 2.5 };
	std::vector<int> vector{ 1, 2, 3, 4, 5 };

	squaring(number);
	squaring(aNumberWithADot);
	squaring(vector);


	return EXIT_SUCCESS;
}

template<typename T>
void squaring(T a)
{
	std::cout << a * a << std::endl;
}

template<>
void squaring(std::vector<int> vector)
{
	for (size_t index{}; index < vector.size(); ++index)
	{
		std::cout << vector[index] * vector[index];
		if (index != vector.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}