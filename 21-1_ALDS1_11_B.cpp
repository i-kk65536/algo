#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Search
{
    int id;
    int begin_time;
    int end_time;

    Search (const int& id=0, const int& begin_time=0, const int& end_time=0) : id(id), begin_time(begin_time), end_time(end_time) {}
    void Print()
    {
        cout << id << " " << begin_time << " " << end_time << endl;
    }
};

class Graph
{
private:
   struct Node
    {
        int id;
        vector<int> adjacency_list;

        Node(const int& id=0, const vector<int>& adjacency_list={}) : id(id), adjacency_list(adjacency_list) {}
    };

    vector<Node> graph;

public:
    Graph(const int& num) : graph(num) {}
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
    stack<Search> DFS()
    {
        stack<Search> result;
        vector<bool> visited(graph.size(), false);
        int time = 0;

        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i])
            {
                break;
            }

            stack<int> stack;
            stack.push(i);
            while (!stack.empty())
            {
                int u = stack.top();
                stack.pop();

                if (!visited[u])
                {
                    visited[u] = true;
                    time++;
                    result.push(Search(graph[u].id, time));

                    for (int e: graph[u].adjacency_list)
                    {
                        if (!visited[e])
                        {
                            stack.push(e);
                        }
                    }

                    time++;
                    result.top().end_time = time;
                }
            }
        }

        return result;
    }
};

int main()
{
    int node_num;
    cin >> node_num;
    Graph graph(node_num);
    graph.input();

    auto result = graph.DFS();
    while (!result.empty())
    {
        result.top().Print();
        result.pop();
    }
}
