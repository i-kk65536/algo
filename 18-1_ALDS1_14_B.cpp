#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cctype>
#include <cstdio>
#include <utility>
#include <string>
#include <vector>
using namespace std;

class IO {
public:
    static inline void read(string &s)
    {
        for (char c; !isspace(c = getchar_unlocked()); s += c);
    }
    static inline void write(int n)
    {
        static char buf[20];
        char *p = buf;
        while (n)
        {
            *p++ = n % 10 + '0';
            n /= 10;
        }
        while (p != buf)
        {
            putchar_unlocked(*--p);
        }
    }
    static inline void write(char c)
    {
        putchar_unlocked(c);
    }
};

void createPartialMatchTable(const string& query, vector<int>& table)
{
    int query_length = query.length();
    table[0] = -1;
    int j = -1;
    for (int i = 0; i < query_length - 1; i++)
    {
        while (j >= 0 && query[i] != query[j])
        {
            j = table[j];
        }
        table[i + 1] = j + 1;
        j++;
    }
}

void KMPfind(const string& text, const string& query)
{
    int text_length = text.length();
    int query_length = query.length();
    if (query_length > text_length)
        return;
    
    vector<int> table(query_length);
    createPartialMatchTable(query, table);
    int top_pos = 0;
    int top_diff = 0;
    while (top_pos + top_diff < text_length)
    {
        if (text[top_pos + top_diff] == query[top_diff])
        {
            top_diff++;
            if (top_diff == query_length)
            {
                IO::write(top_pos);
                IO::write('\n');
                top_pos++;
                top_diff = 0;
            }
        }
        else
        {
            top_pos = top_pos + top_diff - table[top_diff];
            if (top_diff > 0)
                top_diff = table[top_diff];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string text, query;
    IO::read(text);
    IO::read(query);

    KMPfind(text, query);
}
