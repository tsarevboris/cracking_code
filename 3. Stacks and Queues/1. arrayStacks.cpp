#include <vector>

class StacksBatch
{
public:
    StacksBatch(size_t stacksCount, size_t stackLimit)
    {
        _data.resize(stackLimit * stacksCount);
        _stacksSizes.resize(stacksCount);
    }

    void Push(int stackNum, int value)
    {
        if (stackNum >= _stacksCount || IsFull(stackNum)) {
            return;
        }

        _data[GetStackIndex(stackNum) + 1] = value;
        ++_stacksSizes[stackNum];
    }

    void Pop(int stackNum)
    {
        if (stackNum >= _stacksCount || IsEmpty(stackNum)) {
            return;
        }

        --_stacksSizes[stackNum];
    }

    int Top(int stackNum) const
    {
        if (stackNum >= _stacksCount || IsEmpty(stackNum)) {
            return 0;
        }

        return _data[GetStackIndex(stackNum)];
    }

    bool IsEmpty(int stackNum) const
    {
        if (stackNum >= _stacksCount) {
            return true;
        }

        return _stacksSizes[stackNum] == 0;
    }

private:
    size_t GetStackIndex(int stackNum) const
    {
        if (stackNum >= _stacksCount) {
            return 0;
        }

        return stackNum * _stackLimit + _stacksSizes[stackNum];
    }

    bool IsFull(int stackNum)
    {
        if (stackNum >= _stacksCount) {
            return false;
        }

        return _stacksSizes[stackNum] >= _stackLimit;
    }

    size_t _stacksCount;
    size_t _stackLimit;
    std::vector<int> _data;
    std::vector<size_t> _stacksSizes;
};