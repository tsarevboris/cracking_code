#include <iostream>
#include <list>

int findK(const std::list<int>& data, size_t k)
{
    auto iterator = data.cbegin();
    auto secondIterator = std::next(iterator, k);
    while (secondIterator != data.cend()) {
        ++iterator;
        ++secondIterator;
    }
    return *iterator;
}

size_t findKRecursively(std::list<int>::const_iterator iterator, std::list<int>::const_iterator endIterator, size_t k, int& result)
{
    if (iterator == endIterator) {
        return 0;
    }

    const auto number = findKRecursively(std::next(iterator), endIterator, k, result) + 1;
    if (number == k) {
        result = *iterator;
    }
    return number;
}

int findK2(const std::list<int>& data, size_t k)
{
    int result = 0;
    findKRecursively(data.cbegin(), data.cend(), k, result);
    return result;
}

int main()
{
    const std::list<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << findK2(data, 10);
    return 0;
}