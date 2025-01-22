#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leven_shtein_distance(const string& r, const string& c)
{
    string row = " " + r;
    string column = " " + c;
    vector<vector<int>> dp(row.length(), vector<int>(column.length(), 0));

    for (int i = 0; i < row.length(); i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j < column.length(); j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i < row.length(); i++)
    {
        for (int j = 1; j < column.length(); j++)
        {
            int top = dp[i - 1][j] + 1;
            int left = dp[i][j - 1] + 1;
            int top_left = (row[i] == column[j] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1);
            dp[i][j] = min({top, left, top_left});
        }
    }

    return dp[row.length() - 1][column.length() - 1];
}

int main()
{
    string S1, S2;
    cin >> S1 >> S2;

    cout << leven_shtein_distance(S1, S2) << endl;
}