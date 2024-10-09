#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StrKMP
{
private:
    string text;

public:
    StrKMP(const string& t) : text(t) {}
    vector<int> find(const string& query)
    {
        vector<int> match_index;
        if (query.length() > text.length())
            return match_index;
        
        vector<int> table = createPartialMatchTable()
        int i, pos_t, pos_q = 0;
        while (i < text.length() - (query.length() - 1))
        {
            if (i != 0)
            {
                pos_t = i;
                pos_q = table[pos_q];
            }
            while (text[pos_t] == query[pos_q])
            {
                if (pos_q == query.length() - 1)
                {
                    match_index.emplace_back(i);
                    break;
                }
                pos_t++;
                pos_q++;
            }

            pos_t = pos_t + pos_q - table[pos_q];
            pos_q = (pos_q > 0 ? table[pos_q] : pos_q);
        }
        return match_index;
    }
    vector<int> createPartialMatchTable()
    {

    }
};

int main()
{
    string text, query;
    cin >> text >> query;

    StrKMP terget(text);
    vector<int> match_index = terget.find(query);

    for (const auto& e : match_index)
    {
        cout << e << endl;
    }
}