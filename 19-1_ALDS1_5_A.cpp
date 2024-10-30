#include <iostream>
#include <vector>
using namespace std;

bool CanCombine(const vector<int>& list, int target)
{
    int size = list.size();
    vector<vector<bool>> dp(size + 1, vector<bool>(target + 1, false));

    for (int i = 0; i < size + 1; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= list[i - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - list[i - 1]];
            }
        }
    }

    return dp[size][target];
}

int main() {
    int list_size;
    cin >> list_size;
    vector<int> list(list_size);
    for (int& e : list)
    {
        cin >> e;
    }
    int query_size;
    cin >> query_size;
    vector<int> query(query_size);
    for (int& e : query)
    {
        cin >> e;
    }

    for (const int& target : query)
    {
        if (CanCombine(list, target))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
