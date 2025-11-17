#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <chrono>

// Функция для поиска индекса минимального элемента в части вектора
void findMinIndex(const std::vector<int>& arr, int startIdx, std::promise<int> promiseObj)
{
    int min_index{ startIdx };

    // Ищем минимальный элемент в неотсортированной части
    for (int j{ startIdx + 1 }; j < arr.size(); j++)
    {
        if (arr[j] < arr[min_index]) {
            min_index = j;
        }
    }

    // Передаем результат через promise
    promiseObj.set_value(min_index);
}

// Сортировка выбором
void selectionSortAsync(std::vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        // Создаем promise и future для обмена результатом между потоками
        std::promise<int> promise_obj;
        std::future<int> future_obj{ promise_obj.get_future() };

        // Запускаем асинхронную задачу для поиска минимального элемента
        auto future = std::async(std::launch::async, findMinIndex, std::ref(arr), i, std::move(promise_obj));

        // Ждем результат из асинхронной задачи
        int minIndex{ future_obj.get() };

        // Меняем местами найденный минимальный элемент с текущим
        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

// Функция для вывода вектора
void printVector(const std::vector<int>& arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Подключение Русского языка
    setlocale(LC_ALL, "rus");

    std::vector<int> arr1 = { 64, 25, 12, 22, 11, 5, 2, 8, 1, 9 };

    std::cout << "Исходный массив: ";
    printVector(arr1);

    selectionSortAsync(arr1);

    std::cout << "Отсортированный массив: ";
    printVector(arr1);


    return EXIT_SUCCESS;
}