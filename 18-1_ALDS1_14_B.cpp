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
        
        vector<int> table = createPartialMatchTable(query);
        int pos_t = 0;
        int pos_q = 0;
        while (pos_t < text.length())
        {
            if (query[pos_q] == text[pos_t])
            {
                pos_t++;
                pos_q++;
            }
            if (pos_q == query.length() - 1)
            {
                match_index.emplace_back(pos_t - pos_q);
                pos_q = table[pos_q - 1];
            }
            else if (pos_t < text.length() && query[pos_q] != text[pos_t])
            {
                if (pos_q != 0)
                {
                    pos_q = table[pos_q - 1];
                }
                else
                {
                    pos_t++;
                }
            }
        }
        return match_index;
    }
    vector<int> createPartialMatchTable(const string& query)
    {
        vector<int> table(query.length());
        int prefix_length = 0;
        table[0] = 0;
        int i = 1;

        while (i < query.length())
        {
            if (query[i] == query[prefix_length])
            {
                prefix_length++;
                table[i] = prefix_length;
                i++;
            }
            else
            {
                if (prefix_length != 0)
                {
                    prefix_length = table[prefix_length - 1];
                }
                else
                {
                    table[i] = 0;
                    i++;
                }
            }
        }
        return table;
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