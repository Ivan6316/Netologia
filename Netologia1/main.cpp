#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>& vectorOne, std::vector<T>&  vectorTwo);
// Вывод вектора
template<typename T>
void printVector(std::vector<T> vector);

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors(one, two);

	// Вывод вектора для проверки
	printVector(two);


	return EXIT_SUCCESS;
}

template<typename T>
void move_vectors(std::vector<T>& vectorOne, std::vector<T>&  vectorTwo)
{
	vectorTwo = std::move(vectorOne);
}

template<typename T>
void printVector(std::vector<T> vector)
{
	for (const auto& element : vector)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}