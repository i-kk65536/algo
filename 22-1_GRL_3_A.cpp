#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;

public:
    Graph(const int& num) : graph(num) {}
    void insert(const int& v1, const int& v2)
    {
        graph[v1 - 1].push_back(v2);
        graph[v2 - 1].push_back(v1);
    }
    void Print() const
    {
        for (const Node& node : graph)
        {
            cout << node.id;
            for (int adjacency : node.adjacency_list)
            {
                cout << " " << adjacency;
            }
            cout << endl;
        }
    }
};

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph.insert(v1, v2);
    }

    graph.Print();

    return 0;
}