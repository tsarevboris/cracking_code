#include <string>
#include <vector>

class StringBuilder
{
public:
    void Append(std::string str);
    std::string GetString() const;
    size_t Size() const;

private:
    std::vector<std::string> _data;
};
