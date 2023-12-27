#include <iostream>
#include "StringBuilder.h"

int main()
{
    StringBuilder builder;
    std::cout << builder.GetString() << "\n";

    builder.Append("Hello");
    builder.Append(", ");
    builder.Append("world");
    builder.Append("!");
    std::cout << builder.GetString() << "\n";

    return 0;
}