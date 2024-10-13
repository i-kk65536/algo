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
    using iterator = vector<StrMP>::iterator;
    using const_iterator = vector<StrMP>::const_iterator;
    iterator begin() { return field.begin(); }
    iterator end() { return field.end(); }
    const_iterator begin() const { return field.begin(); }
    const_iterator end() const { return field.end(); }

    vector<Point> find(const vector<string>& query)
    {
        vector<Point> match_index;
        int query_height = query.size();
        int query_width = query[0].length();
        for (int i = 0; i < terget_height - query_height + 1; i++)
        {
            vector<int> match_top = field[i].find(query[0]);
            if (!match_top.empty())
            {
                for (int& match_pos : match_top)
                {
                    bool match = true;
                    for (int j = 1; j < query_height; j++)
                    {
                        if (field[i + j].substr(match_pos, query_width) != query[j])
                        {
                            match = false;
                            break;
                        }
                    }
                    if (match)
                    {
                        match_index.emplace_back(Point(i, match_pos));
                    }
                }
            }
        }
        return match_index;
    }
};

int main()
{
    int terget_height, terget_width;
    cin >> terget_height >> terget_width;
    StrMP2d terget(terget_height);
    for (StrMP& row : terget)
    {
        string str;
        cin >> str;
        row = StrMP(str);
    }
    int query_height, query_width;
    cin >> query_height >> query_width;
    vector<string> query(query_height);
    for (string& row : query)
    {
        cin >> row;
    }

    vector<Point> match_index = terget.find(query);
    for (const auto& point : match_index)
        cout << point.x << " " << point.y << endl;
}
