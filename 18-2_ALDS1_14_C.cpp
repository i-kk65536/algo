#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Point
{
public:
    int x;
    int y;

    Point(const int& x, const int& y) : x(x), y(y) {}
};

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
    StrMP() {}
    StrMP(const string& text) : text(text) {}

    vector<int> find(const string& query)
    {
        vector<int> match_index;
        int text_length = text.length();
        int query_length = query.length();
        if (query_length > text_length)
            return match_index;
        
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
                match_index.emplace_back(text_pos - (query_length - 1));
                top_diff = table[top_diff];
            }
        }
        return match_index;
    }
    string substr(const int& start, const int& diff)
    {
        return text.substr(start, diff);
    }
};

class StrMP2d
{
private:
    vector<StrMP> field;
    int terget_height;

public:
    StrMP2d(int height) : field(height), terget_height(height) {}

    void insert(const string& text, const int& index)
    {
        field.at(index) = StrMP(text);
    }
    void find(const vector<string>& query)
    {
        int query_height = query.size();
        int query_width = query[0].length();
        for (int i = 0; i < terget_height - query_height + 1; i++)
        {
            vector<int> match_top = field[i].find(query[0]);
            if (!match_top.empty())
            {
                bool previous_match = false;
                for (int k = 0; k < match_top.size(); k++)
                {
                    bool match = true;
                    for (int j = 1; j < query_height; j++)
                    {
                        int diff_prev = (k > 0 ? match_top[k - 1] + query_width - match_top[k] : 0);
                        if (previous_match && diff_prev > 0)
                        {
                            previous_match = false;
                            if (field[i + j].substr(match_top[k] + diff_prev, query_width - diff_prev) != query[j].substr(diff_prev))
                            {
                                match = false;
                                break;
                            }
                        }
                        else
                        {
                            if (field[i + j].substr(match_top[k], query_width) != query[j])
                            {
                                match = false;
                                break;
                            }
                        }
                    }
                    if (match)
                    {
                        cout << i << " " << match_top[k] << endl;
                        previous_match = true;
                    }
                }
            }
        }
    }
};

int main()
{
    int terget_height, terget_width;
    cin >> terget_height >> terget_width;
    StrMP2d terget(terget_height);
    for (int i = 0; i < terget_height; i++)
    {
        string str;
        cin >> str;
        terget.insert(str, i);
    }
    int query_height, query_width;
    cin >> query_height >> query_width;
    vector<string> query(query_height);
    for (string& row : query)
    {
        cin >> row;
    }

    terget.find(query);
}
