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
public:
    StrMP(const string& text) : text(text) {}

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
};

int main()
{
    string text, query;
    cin >> text >> query;

    StrMP terget(text);
    terget.find(query);
}
