#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<int> discoveryTime, low, parent;
    vector<bool> visited, articulationPoint;
    int time;

    void DFS(int u)
    {
        int children = 0;
        visited[u] = true;
        discoveryTime[u] = low[u] = ++time;

        for (int v : adjList[u])
        {
            if (!visited[v])
            {
                children++;
                parent[v] = u;
                DFS(v);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1)
                    articulationPoint[u] = true;
                if (parent[u] != -1 && low[v] >= discoveryTime[u])
                    articulationPoint[u] = true;
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], discoveryTime[v]);
            }
        }
    }

public:
    Graph(int vertices) : vertices(vertices), adjList(vertices), time(0), parent(vertices, -1), visited(vertices, false), articulationPoint(vertices, false), discoveryTime(vertices, -1), low(vertices, -1) {}

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void findArticulationPoints()
    {
        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }

        for (int i = 0; i < vertices; i++)
        {
            if (articulationPoint[i])
            {
                cout << i << endl;
            }
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
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    graph.findArticulationPoints();

    return 0;
}
