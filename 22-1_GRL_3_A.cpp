#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;

public:
    Graph(const int& vertices) : graph(vertices) {}
    vector<int>& operator[](size_t index) 
    {
        return graph[index];
    }
    vector<int> ArticulationPoint()
    {
        
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
        graph[v1].emplace_back(v2);
    }

    for (const int& e: graph.ArticulationPoint())
        cout << e << endl;
}
