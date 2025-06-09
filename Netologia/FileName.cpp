#include <iostream>

int main()
{
	// Подключение Русского языка
	setlocale(LC_ALL, "rus");

	std::string name{};
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << "!" << std::endl;

	return EXIT_SUCCESS;
}