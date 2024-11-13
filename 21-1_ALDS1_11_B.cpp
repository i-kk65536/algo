#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
   struct Node
    {
        int id;
        vector<int> adjacency_list;
        int begin_time;
        int end_time;
        bool finded = false;

        Node(const int& id=0, const vector<int>& adjacency_list={}) : id(id), adjacency_list(adjacency_list) {}
    };

    vector<Node> graph;
    vector<int> begin_time;
    vector<int> end_time;

public:
    Graph(const int& num) : graph(num), begin_time(num), end_time(num) {}
    void input()
    {
        for (Node& node: graph)
        {
            cin >> node.id;
            int outdegree;
            cin >> outdegree;
            node.adjacency_list.resize(outdegree);
            for (int& adjacency: node.adjacency_list)
                cin >> adjacency;
        }
    }
    Graph& DFS()
    {
        return *this;
    }
    void print()
    {
        for (const Node& node: graph)
            cout << node.id << " " << node.begin_time << " " << node.end_time;
    }
};


int main()
{
    int node_num;
    cin >> node_num;
    Graph graph(node_num);
    graph.input();

    graph.DFS().print();
}
