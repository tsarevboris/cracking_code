#include <iostream>
#include <string>

bool canModify(const std::string& str1, const std::string& str2)
{
    // Оптимизация. Если разница длин больше 1, то точно false
    if (std::abs(static_cast<int>(str1.size()) - static_cast<int>(str2.size())) > 1) {
        return false;
    }

    // Проходимся и сравниваем. Допускается одно различие.
    const bool sameSize = str1.size() == str2.size();
    const std::string& smallString = str1.size() < str2.size() ? str1 : str2;
    const std::string& bigString = str1.size() >= str2.size() ? str1 : str2;

    bool hasDiff = false;
    size_t smallIndex = 0;
    size_t bigIndex = 0;

    // Один раз проходимся по строкам. Сложность N + M
    while (smallIndex < smallString.size() && bigIndex < bigString.size()) {
        if (smallString[smallIndex] != bigString[bigIndex]) {
            // Различие уже было, а еще одно не допускается.
            if (hasDiff) {
                return false;
            } else {
                hasDiff = true;
                
                // По большой строке всегда двигаемся, а в маленькой допускаем один пропуск.
                ++bigIndex;
                if (sameSize) {
                    ++smallIndex;
                }
            }
        } else {
            // Символы совпадают, идем дальше
            ++smallIndex;
            ++bigIndex;
        }
    }

    // Если не было отличий, или было одно и дошли до конца обеих строк, то все ок.
    return true;
}

void test(const std::string& str1, const std::string& str2, bool result)
{
    std::cout << "Testing " << str1 << " - " << str2 << " : " << (canModify(str1, str2) == result ? "succeeded" : "failed") << std::endl;
}

int main()
{
    test("ale", "a", false);
    test("ale", "pale", true);
    test("ali", "pale", false);
    test("pale", "ple", true);
    test("pales", "pale", true);
    test("pale", "bale", true);
    test("pale", "bake", false);
    test("", "", true);
    test("", "2", true);
    test("1", "", true);

    return 0;
}