#include <memory>
#include <vector>
#include <queue>
#include <iostream>
#include <optional>

template<typename T>
class BinaryTreeNode
{
public:
    using Type = BinaryTreeNode<T>;
    using Ptr = std::unique_ptr<Type>;

    BinaryTreeNode() = default;
    BinaryTreeNode(T value) : _value(value) { }

    void SetValue(T value)
    {
        _value = value;
    }

    const T& GetValue() const
    {
        return _value;
    }

    Type* GetLeft() const
    {
        return _leftChild.get();
    }

    Type* GetRight() const
    {
        return _rightChild.get();
    }

    void SetLeft(T value)
    {
        _leftChild = Ptr(new Type(value));
    }

    void SetRight(T value)
    {
        _rightChild = Ptr(new Type(value));
    }

private:
    T _value;
    Ptr _leftChild;
    Ptr _rightChild;
};

template<typename T>
class BinaryTree
{
public:
    void AddToEnd(T value)
    {
        if (!_root) {
            SetRoot(value);
            return;
        }

        std::queue<NodeType*> nodes;
        nodes.push(_root.get());

        while (!nodes.empty()) {
            const auto node = nodes.front();
            if (auto leftChild = node->GetLeft(); leftChild) {
                nodes.push(leftChild);
            } else {
                node->SetLeft(value);
                return;
            }

            if (auto rightChild = node->GetRight(); rightChild) {
                nodes.push(rightChild);
            } else {
                node->SetRight(value);
                return;
            }

            nodes.pop();
        }
    }

    bool IsSearchTree() const
    {
        return IsSearchTree(_root.get(), {}, {});
    }

    std::vector<std::vector<T>> GetLayers() const
    {
        if (!_root) {
            return {};
        }

        std::vector<std::vector<T>> allLayers;
        std::vector<NodeType*> nodes;
        nodes.push_back(_root.get());

        while (!nodes.empty()) {
            std::vector<NodeType*> nextNodes;
            for (const auto node : nodes) {
                if (const auto leftChild = node->GetLeft(); leftChild) {
                    nextNodes.push_back(leftChild);
                }
                if (const auto rightChild = node->GetRight(); rightChild) {
                    nextNodes.push_back(rightChild);
                }
            }

            std::vector<T> layer(nodes.size());
            std::transform(nodes.cbegin(), nodes.cend(), layer.begin(), [](const auto node) {
                return node->GetValue();
            });

            allLayers.push_back(layer);
            nodes = std::move(nextNodes);
        }

        return std::move(allLayers);
    }

private:
    using NodeType = typename BinaryTreeNode<T>::Type;
    using NodePtr = typename BinaryTreeNode<T>::Ptr;

    void SetRoot(T value)
    {
        _root = NodePtr(new NodeType(value));
    }

    bool IsSearchTree(NodeType* node, std::optional<T> min, std::optional<T> max) const
    {
        if (!node) {
            return true;
        }

        const auto& value = node->GetValue();
        if (min.has_value() && value < min) {
            return false;
        }
        if (max.has_value() && value >= max) {
            return false;
        }

        return IsSearchTree(node->GetLeft(), min, value) && IsSearchTree(node->GetRight(), value, max);
    }

    NodePtr _root;
};

int main()
{
    BinaryTree<int> tree;
    for (auto value : {10, 2, 14, 1, 8, 11, 15, 0, 1}) {
        tree.AddToEnd(value);
    }

    const auto layers = tree.GetLayers();
    for (size_t layerIndex = 0; layerIndex < layers.size(); ++layerIndex) {
        for (size_t i = 0; i < (layers.size() - layerIndex); ++i) {
            std::cout << " ";
        }
        for (const auto& value : layers[layerIndex]) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Is search tree: " << tree.IsSearchTree() << "\n";

    return 0;
}