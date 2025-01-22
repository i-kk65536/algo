#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, cost;
};

vector<int> dijkstra(int n, vector<vector<Edge>>& graph) {
    vector<int> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& e : graph[u]) {
            if (dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    return dist;
}

int main() {
    int n;
    cin >> n;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v, c;
            cin >> v >> c;
            graph[u].push_back({v, c});
        }
    }

    vector<int> dist = dijkstra(n, graph);

    for (int i = 0; i < n; ++i) {
        cout << i << " " << dist[i] << endl;
    }
}