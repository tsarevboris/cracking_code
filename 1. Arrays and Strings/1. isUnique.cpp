// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>

bool isUniqueMap(const std::string& str)
{
    std::unordered_set<char> symbols;
    for (const auto s : str) {
        if (symbols.find(s) != symbols.cend()) {
            return false;
        }
        symbols.insert(s);
    }
    return true;
}

bool isUniqueSort(const std::string& str)
{
    std::string strCopy(str);
    std::sort(strCopy.begin(), strCopy.end());
    for (size_t i = 1; i < strCopy.size(); ++i) {
        if (strCopy[i - 1] == strCopy[i]) {
            return false;
        }
    }
    return true;
}

void test(const std::string& str, bool isUnique)
{
    std::cout << "Testing " << str << "\n";
    std::cout << "  isUniqueMap - " << (isUniqueMap(str) == isUnique ? "success" : "failure") << "\n";
    std::cout << "  isUniqueSort - " << (isUniqueSort(str) == isUnique ? "success" : "failure") << "\n\n";
}

int main()
{
    test("abc", true);
    test("aabc", false);
    test("", true);
    test("Aabc", true);
    test("djf33", false);
}
