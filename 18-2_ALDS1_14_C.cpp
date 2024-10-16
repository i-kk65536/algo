#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ull = unsigned long long;

struct Point
{
public:
    int x;
    int y;

    Point(const int& x, const int& y) : x(x), y(y) {}
};

class Hash2d
{
private:
    vector<vector<ull>> field;
public:
    Hash2d() {}
};

int main()
{
    int terget_height, terget_width;
    cin >> terget_height >> terget_width;
    vector<string> terget_raw(terget_height);
    for (string& row : terget_raw)
    {
        cin >> row;
    }
    int query_height, query_width;
    cin >> query_height >> query_width;
    vector<string> query_raw(query_height);
    for (string& row : query_raw)
    {
        cin >> row;
    }

    Hash2d terget(terget_raw, query_height, query_width);
    Hash2d query(query_raw, query_height, query_width);
    terget.find(query);
}
