#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

template<typename T>
class Graph
{
public:
    void AddNode(T value)
    {
        _nodes.push_back({value, false});
    }

    template<typename... Args>
    void AddNodes(Args... args)
    {
        (..., AddNode(args));
    }

    void AddEdge(size_t from, size_t to)
    {
        _adjacencyList[from].push_back(to);
    }

    bool HasPath(size_t from, size_t to)
    {
        std::for_each(_nodes.begin(), _nodes.end(), [](auto& node) { node.visited = false; });

        std::queue<size_t> indices;
        indices.push(from);

        while (!indices.empty()) {
            _nodes[indices.front()].visited = true;

            if (indices.front() == to) {
                return true;
            }
            for (const auto index : _adjacencyList[indices.front()]) {
                if (!_nodes[index].visited) {
                    indices.push(index);
                }
            }
            indices.pop();
        }

        return false;
    }

private:
    struct Node
    {
        T value;
        bool visited;
    };

    std::vector<Node> _nodes;
    std::unordered_map<size_t, std::vector<size_t>> _adjacencyList;
};

int main()
{
    Graph<int> g;
    g.AddNodes(0, 1, 2, 3, 4, 5);
    
    g.AddEdge(0, 1);
    g.AddEdge(0, 4);
    g.AddEdge(0, 5);
    g.AddEdge(1, 3);
    g.AddEdge(1, 4);
    g.AddEdge(2, 1);
    g.AddEdge(3, 2);
    g.AddEdge(3, 4);

    std::cout << std::endl;
    std::cout << g.HasPath(0, 3) << "\n";
    std::cout << g.HasPath(5, 4) << "\n";
    return 0;
}