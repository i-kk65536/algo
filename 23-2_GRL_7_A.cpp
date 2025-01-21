#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class BipartiteGraph {
private:
    vector<vector<int>> graph;
    vector<int> match;
    vector<bool> used;
    int vertex;

    bool dfs(int v) {
        used[v] = true;
        for (int i = 0; i < graph[v].size(); i++) {
            int u = graph[v][i], w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteGraph(int V) : graph(V), match(V, -1), used(V, false), vertex(V) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int bipartite_matching() {
        int res = 0;
        fill(match.begin(), match.end(), -1);
        for (int v = 0; v < vertex; v++) {
            if (match[v] < 0) {
                fill(used.begin(), used.end(), false);
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    int X, Y, E;
    cin >> X >> Y >> E;
    BipartiteGraph graph(X + Y);
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        graph.add_edge(x, X + y);
    }

    int edge = graph.bipartite_matching();
    cout << edge << endl;
}