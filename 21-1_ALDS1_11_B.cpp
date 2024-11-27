#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int id;
    vector<int> adjacency_list;

    Node(const int& id=0, const vector<int>& adjacency_list={}) : id(id), adjacency_list(adjacency_list) {}
};
struct Search
{
    int id;
    int start_time;
    int end_time;

    Search (const int& id=0, const int& start_time=0, const int& end_time=0) : id(id), start_time(start_time), end_time(end_time) {}
    void Print() const
    {
        cout << id << " " << start_time << " " << end_time << endl;
    }
};

class Graph
{
private:
    vector<Node> graph;

    void DFSVisit(int node, int& time, vector<bool>& visited, vector<Search>& search_result)
    {
        visited[node] = true;
        search_result[node].id = node + 1;
        search_result[node].start_time = ++time;

        for (int adjacency : graph[node].adjacency_list)
        {
            if (!visited[adjacency - 1])
            {
                DFSVisit(adjacency - 1, time, visited, search_result);
            }
        }

        search_result[node].end_time = ++time;
    }

public:
    Graph(const int& num) : graph(num) {}
    void insert(const Node& node)
    {
        graph[node.id - 1] = node;
    }
    vector<Search> DFS()
    {
        vector<Search> search_result(graph.size());
        vector<bool> visited(graph.size(), false);
        int time = 0;

        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {
                DFSVisit(i, time, visited, search_result);
            }
        }

        return search_result;
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

    for (const Search& search: graph.DFS())
    {
        search.Print();
    }
}
