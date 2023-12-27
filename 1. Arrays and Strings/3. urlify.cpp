#include <iostream>
#include <cstdlib>
#include <numeric>

void urlify(char* str, int len)
{
    // Ищем кол-во пробелов за O(N)
    int spacesCount = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            ++spacesCount;
        }
    }

    // Строим строку с конца за O(N)
    int insertPos = len + spacesCount * 2 - 1;
    for (int readPos = len - 1; readPos >= 0; --readPos) {
        if (str[readPos] == ' ') {
            str[insertPos--] = '0';
            str[insertPos--] = '2';
            str[insertPos--] = '#';
        } else {
            str[insertPos--] = str[readPos];
        }
    }
}

int main()
{
    char str[] = " Hello string  with spaces          ";
    urlify(str, 26);
    std::cout << str;
}