#include <iostream>

std::string compressString(const std::string& str)
{
    std::string compressedStr;
    compressedStr.resize(str.size());

    int sameSymbolsCount = 0;
    size_t currentPos = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        // Считаем очередной символ
        ++sameSymbolsCount;

        // Если дальше идет другой символ или это последний, то записываем, иначе просто идем дальше
        if (i == str.size() - 1 || str[i] != str[i + 1]) {
            const auto countStr = std::to_string(sameSymbolsCount);

            // Сжатая строка получается уже не короче исходной, возвращаем исходную.
            if (currentPos + countStr.size() >= str.size()) {
                return str;
            }

            compressedStr[currentPos++] = str[i];
            for (size_t j = 0; j < countStr.size(); ++j) {
                compressedStr[currentPos++] = countStr[j];
            }

            sameSymbolsCount = 0;
        }
    }

    compressedStr.resize(currentPos);
    return compressedStr;
}

void test(const std::string& str, const std::string& compressed)
{
    std::cout << "Testing " << str << " - " << compressString(str) << " - " << (compressString(str) == compressed ? "succeeded" : "failed") << std::endl;
}

int main()
{
    test("aabcccccaaa", "a2b1c5a3");
    test("", "");
    test("bbbbb", "b5");
    test("abcde", "abcde");
    test("abcdeee", "abcdeee");
    return 0;
}