#include <iostream>
#include <unordered_map>

bool isPermutation(const std::string& str1, const std::string& str2)
{
    if (str1.size() != str2.size()) 
        return false;
        
    std::unordered_map<char, int> symbolsCount;
    for (const auto s : str1) {
        ++symbolsCount[s];
    }
    
    for (const auto s : str2) {
        --symbolsCount[s];
        if (symbolsCount[s] < 0)
            return false;
    }
    
    return true;
}

void test(const std::string& str1, const std::string& str2, bool result)
{
    std::cout << "Testing " << str1 << " - " << str2 << " : " << (isPermutation(str1, str2) == result ? "succeeded" : "failed") << std::endl;
}

int main()
{
    test("", "", true);
    test("ab", "ab", true);
    test("acbda", "bcd", false);
    test("adaa", "ddaa", false);
    test("Abc", "abc", false);
}
