#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

class FlowNetwork {
private:
    struct Edge {
        int to;
        int capacity;
        int rev;
        Edge(int to, int capacity, int rev) : to(to), capacity(capacity), rev(rev) {}
    };

    vector<vector<Edge>> graph;
    vector<bool> used;

    int dfs(int v, int t, int f) {
        if (v == t)
            return f;

        used[v] = true;
        for (int i = 0; i < graph[v].size(); i++) {
            Edge &e = graph[v][i];
            if (!used[e.to] && e.capacity > 0) {
                int d = dfs(e.to, t, min(f, e.capacity));
                if (d > 0) {
                    e.capacity -= d;
                    graph[e.to][e.rev].capacity += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    FlowNetwork(int V) : graph(V), used(V) {}

    void add_edge(int from, int to, int capacity) {
        graph[from].push_back(Edge(to, capacity, (int)graph[to].size()));
        graph[to].push_back(Edge(from, 0, (int)graph[from].size() - 1));
    }
    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, INT_MAX);
            if (f == 0)
                break;
            flow += f;
        }
        return flow;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    FlowNetwork graph(V);
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.add_edge(u, v, c);
    }

    cout << graph.max_flow(0, V - 1) << endl;
}