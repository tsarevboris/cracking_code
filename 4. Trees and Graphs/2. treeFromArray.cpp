#include <memory>
#include <vector>

template<typename T>
struct BinaryTreeNode
{
    T value;
    std::unique_ptr<BinaryTreeNode<T>> leftChild;
    std::unique_ptr<BinaryTreeNode<T>> rightChild;
};

template<typename T>
struct BinaryTree
{
    std::unique_ptr<BinaryTreeNode<T>> root;
};

template<typename T>
std::unique_ptr<BinaryTreeNode<T>> TreeFromVector(const std::vector<T>& values, size_t left, size_t right)
{
    if (left > right) {
        return nullptr;
    }

    const auto middle = left + (right - left) / 2;
    auto node = std::make_unique<BinaryTreeNode<T>>();
    node->value = values[middle];
    node->leftChild = TreeFromVector(values, left, middle - 1);
    node->rightChild = TreeFromVector(values, middle + 1, right);
    return node;
}

template<typename T>
BinaryTree<T> TreeFromVector(const std::vector<T>& values)
{
    return TreeFromVector(values, size_t(0), values.size() - 1);
}

int main()
{
    return 0;
}