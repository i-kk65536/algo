#include <iosteream>
#include <string>
#include <vector>
using namespace std;

class StrExpand
{
private:
    string terget;

public:
    StrFind(string t) : terget(t) {}
    vector<int> find(string query)
    {
        for (int pos_t = 0; pos_t < terget.length() - query.length() + 1; pos_t++)
        {
            int pos_q = 0;
            while (terget[pos_t] == query[pos_q])
            {
                if (query.length() - 1 == pos_q)
                {
                    return pos_t;
                }
                pos_q++;
            }
        }
    }
};

int main()
{
    string t, q;
    cin >> t >> q:

    StrExpand terget(t);
    vector<int> match_index = terget.find(p);

    if (!match_index)
        return;
    for (const auto& e : match_index)
    {
        cout << e << endl;
    }
}