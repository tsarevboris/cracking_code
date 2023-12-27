#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>

void toLower(char* symbol)
{
    if ('A' <= *symbol && *symbol <= 'Z')
        *symbol += ('a' - 'A');
}

bool isPalindromePermutation(const char* string)
{
    std::unordered_map<char, bool> symbols;
    
    const int stringLength = std::strlen(string);
    for (int i = 0; i < stringLength; ++i) {
        char symbol = string[i];
        toLower(&symbol);
        
        if (symbol == ' ')
            continue;
 
        symbols[symbol] = !symbols[symbol];
    }
    
    const auto oddCount = std::count_if(symbols.cbegin(), symbols.cend(), [](const auto& pair) {
        return pair.second;
    });
    return oddCount <= 1;
}

void test(const char* string, bool result)
{
    std::cout << std::boolalpha << string << " - " << result << " - ";
    std::cout << (isPalindromePermutation(string) == result ? "succeeded" : "failed") << std::endl;
}

int main()
{
    test("Tact Coa", true);
    test("test me", false);
    test("test me em test", true);
    test("", true);
}
