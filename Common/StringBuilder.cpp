#include "StringBuilder.h"
#include <numeric>

void StringBuilder::Append(std::string str)
{
    _data.push_back(std::move(str));
}

std::string StringBuilder::GetString() const
{
    std::string result;
    result.resize(Size());

    size_t insertPos = 0;
    for (const auto& str : _data) {
        std::copy(str.cbegin(), str.cend(), result.begin() + insertPos);
        insertPos += str.size();
    }

    return result;
}

size_t StringBuilder::Size() const
{
    return std::accumulate(_data.cbegin(), _data.cend(), 0, [](size_t sum, const auto& str) {
        return sum + str.size();
    });
}