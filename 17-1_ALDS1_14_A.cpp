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
        vector<int> match_index();
        for (int i = 0; i < terget.length() - (query.length() - 1); i++)
        {
            int pos_t = 0;
            int pos_q = 0;
            while (terget[i + pos_t] == query[pos_q])
            {
                if (query.length() - 1 == pos_q)
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
    string t, q;
    cin >> t >> q:

    StrExpand terget(t);
    vector<int> match_index = terget.find(p);

    for (const auto& e : match_index)
    {
        cout << e << endl;
    }
}