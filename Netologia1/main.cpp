#include <iostream>
#include <fstream>

// Изначальный класс
class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

// Класс, который пишет message в консоль
class OutputToTheConsole : public LogCommand
{
public:
    void print(const std::string& message) override
    {
        // Вывод message в консоль
        std::cout << message << std::endl;
    }
};

// Класс, который записывает message в файл
class WritingToAFile : public LogCommand
{
private:
    std::string _filePath_{};

public:
    WritingToAFile(const std::string& path) : _filePath_(path) {}

    void print(const std::string& message) override
    {
        // Открытие файла в режиме добавления
        std::ofstream file(_filePath_, std::ios::app);
        // Проверка на открытие
        if (!file.is_open())
        {
            std::cerr << "Error when opening a file: " << _filePath_ << std::endl;
        }
        else
        {
            // Сохранение message в файл
            file << message << std::endl;

            file.close();
        }
    }
};

// Функция для выполнения команды
void print(LogCommand& command);

int main()
{
    // Подключение Русского языка
    setlocale(LC_ALL, "rus");

    // Создание команд
    OutputToTheConsole consoleCommand;
    WritingToAFile fileCommand("input.txt");

    // Выполняем команду вывода в консоль
    std::cout << "Тест вывода в консоль:" << std::endl;
    print(consoleCommand);

    // Выполняем команду вывода в файл
    std::cout << "\nТест вывода в файл" << std::endl;
    print(fileCommand);


	return EXIT_SUCCESS;
}

void print(LogCommand& command)
{
    command.print("Выполнение команды логирования");
}