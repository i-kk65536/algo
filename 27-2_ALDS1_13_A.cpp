#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 8;
vector<string> board(N, string(N, '.'));
vector<bool> row(N, false), col(N, false), diag1(2 * N - 1, false), diag2(2 * N - 1, false);

bool solve(int r) {
    if (r == N) return true;
    if (row[r]) return solve(r + 1);
    for (int c = 0; c < N; ++c) {
        if (!col[c] && !diag1[r + c] && !diag2[r - c + N - 1]) {
            board[r][c] = 'Q';
            row[r] = col[c] = diag1[r + c] = diag2[r - c + N - 1] = true;
            if (solve(r + 1)) return true;
            board[r][c] = '.';
            row[r] = col[c] = diag1[r + c] = diag2[r - c + N - 1] = false;
        }
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 'Q';
        row[r] = col[c] = diag1[r + c] = diag2[r - c + N - 1] = true;
    }
    solve(0);
    for (const auto& line : board) {
        cout << line << endl;
    }
    return 0;
}