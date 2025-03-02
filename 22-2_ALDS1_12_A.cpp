#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

int primMST(vector<vector<int>>& graph, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0;
    int res = 0;
    
    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        
        res += key[u];
        inMST[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != -1 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << primMST(graph, n) << endl;

    return 0;
}
