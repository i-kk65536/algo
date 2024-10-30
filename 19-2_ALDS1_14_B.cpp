#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class StrBM
{
private:
    string target;

    vector<int> createBadCharTable(const string& query)
    {
        const int ALPHABET_SIZE = 256;
        vector<int> badCharTable(ALPHABET_SIZE, -1);

        for (int i = 0; i < query.size(); i++)
        {
            badCharTable[static_cast<int>(query[i])] = i;
        }

        return badCharTable;
    }

public:
    StrBM(string t) : target(t) {}

    vector<int> find(const string& query)
    {
        vector<int> match_index;
        int n = target.size();
        int m = query.size();

        if (m > n)
            return match_index;

        vector<int> badCharTable = createBadCharTable(query);

        int shift = 0;
        while (shift <= (n - m))
        {
            int j = m - 1;

            while (j >= 0 && query[j] == target[shift + j])
            {
                j--;
            }

            if (j < 0)
            {
                match_index.emplace_back(shift);
                shift += (shift + m < n) ? m - badCharTable[static_cast<int>(target[shift + m])] : 1;
            }
            else
            {
                shift += max(1, j - badCharTable[static_cast<int>(target[shift + j])]);
            }
        }
        return match_index;
    }
};

int main()
{
    string t, q;
    cin >> t >> q;

    StrBM target(t);
    vector<int> match_index = target.find(q);

    for (const auto& e : match_index)
    {
        cout << e << endl;
    }
}
