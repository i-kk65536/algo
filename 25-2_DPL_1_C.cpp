#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> value(N), weight(N);
    for (int i = 0; i < N; ++i) {
        cin >> value[i] >> weight[i];
    }

    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int w = weight[i]; w <= W; ++w) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[W] << endl;
    return 0;
}