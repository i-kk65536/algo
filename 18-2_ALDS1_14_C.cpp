#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StrMP
{
private:
    string text;

    void createPartialMatchTable(const string& query, vector<int>& table)
    {
        int query_length = query.length();
        table[0] = -1;
        int j = -1;
        for (int i = 1; i < query_length; i++)
        {
            while (j >= 0 && query[i] != query[j + 1])
            {
                j = table[j];
            }
            if (query[i] == query[j + 1])
            {
                j++;
            }
            table[i] = j;
        }
    }
    void find(const string& query)
    {
        int text_length = text.length();
        int query_length = query.length();
        if (query_length > text_length)
            return;
        
        vector<int> table(query_length);
        createPartialMatchTable(query, table);
        int text_pos = 0;
        int top_diff = -1;
        for (; text_pos < text_length; text_pos++)
        {
            while (top_diff >= 0 && text[text_pos] != query[top_diff + 1])
            {
                top_diff = table[top_diff];
            }
            if (text[text_pos] == query[top_diff + 1])
            {
                top_diff++;
            }
            if (top_diff == query_length - 1)
            {
                cout << text_pos - (query_length - 1) << '\n';
                top_diff = table[top_diff];
            }
        }
    }
public:
    StrMP() {}
    StrMP(const string& text) : text(text) {}

    void find2d(const vector<StrMP>& query)
    {

    }
};

int main()
{
    int text_height, text_width;
    cin >> text_height >> text_width;
    vector<StrMP> field(text_height);
    for (auto& strmp : field)
    {
        string text;
        cin >> text;
        strmp = StrMP(text);
    }
    int query_height, query_width;
    cin >> query_height >> query_width;
    vector<StrMP> pattern(text_height);
    for (auto& strmp : pattern)
    {
        string text;
        cin >> text;
        strmp = StrMP(text);
    }

    field.find2d(pattern);
}
