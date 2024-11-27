#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int id;
    vector<int> adjacency_list;

    Node(const int& id=0, const vector<int>& adjacency_list={}) : id(id), adjacency_list(adjacency_list) {}
};
struct Distance
{
    int id;
    int distance;

    Distance (const int& id=0, const int& distance=0) : id(id), distance(distance) {}
    void Print() const
    {
        cout << id << " " << distance << endl;
    }
};

class Graph
{
private:
    vector<Node> graph;

public:
    Graph(const int& num) : graph(num) {}
    void insert(const Node& node)
    {
        graph[node.id - 1] = node;
    }
    vector<int> BFS()
    {
        vector<int> distance(graph.size(), -1);
        queue<int> q;
        int start_node = 0;

        distance[start_node] = 0;
        q.push(start_node);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int adjacency : graph[node].adjacency_list)
            {
                if (distance[adjacency - 1] == -1)
                {
                    distance[adjacency - 1] = distance[node] + 1;
                    q.push(adjacency - 1);
                }
            }
        }

        return distance;
    }
};

int main()
{
    int node_num;
    cin >> node_num;
    Graph graph(node_num);
    for (int i = 0; i < node_num; i++)
    {
        int id, outdegree;
        cin >> id >> outdegree;
        vector<int> adjacency_list(outdegree);
        for (int& adjacency : adjacency_list)
            cin >> adjacency;
        graph.insert(Node(id, adjacency_list));
    }

    vector<int> distance = graph.BFS();
    for (int i = 0; i < distance.size(); i++)
    {
        cout << i + 1 << " " << distance[i] << endl;
    }
}
