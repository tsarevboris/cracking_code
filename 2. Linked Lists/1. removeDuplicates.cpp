#include <list>
#include <unordered_set>
#include <iostream>

void removeDuplicates(std::list<int>& data)
{
    std::unordered_set<int> buffer;
    for (auto iterator = data.begin(); iterator != data.end();) {
        if (buffer.contains(*iterator)) {
            iterator = data.erase(iterator);
        } else {
            buffer.insert(*iterator);
            ++iterator;
        }
    }
}

void removeDuplicates2(std::list<int>& data)
{
    for (auto iterator = data.begin(); iterator != data.end(); ++iterator) {
        for (auto secondIterator = std::next(iterator); secondIterator != data.end();) {
            if (*iterator == *secondIterator) {
                secondIterator = data.erase(secondIterator);
            } else {
                ++secondIterator;
            }
        }
    }
}

int main()
{
    std::list<int> data = {  1, 2, 3, 5, 3, 5, 6, 9, 1, 3, 10};
    removeDuplicates2(data);

    for (const auto value : data) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}