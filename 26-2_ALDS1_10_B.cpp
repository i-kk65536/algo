#include <iostream>
#include <vector>

using namespace std;

struct Matrix
{
    int row;
    int column;

    Matrix(int row = 0, int column = 0) : row(row), column(column) {}
};

int calc_multiplication(const vector<Matrix>& mat_chain)
{
    int n = mat_chain.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + mat_chain[i].row * mat_chain[k].column * mat_chain[j].column;
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int mat_num;
    cin >> mat_num;
    vector<Matrix> mat_chain(mat_num);
    for (int i = 0; i < mat_num; i++)
    {
        cin >> mat_chain[i].row >> mat_chain[i].column;
    }

    cout << calc_multiplication(mat_chain) << endl;
}