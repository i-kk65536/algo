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
            
        for (int i = 0; i < text.length() - (query.length() - 1); i++)
        {
            int pos_t = i;
            int pos_q = 0;
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
        }
        return match_index;
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