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
    vector<int> find(const string& query, vector<int>& match_index)
    {
        if (query.length() > text.length())
            return;
        
        vector<int> table(query.length());
        createPartialMatchTable(query, table);
		int top_pos = 0;
		int top_diff = 0;
    	while (top_pos + top_diff < text.length())
		{
        	if (text[top_pos + top_diff] == query[top_diff])
			{
        		top_diff++;
        		if (top_diff == query.length())
        		{
         	       match_index.emplace_back(top_pos);
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
    vector<int> createPartialMatchTable(const string& query, vector<int>& table)
    {
        table[0] = -1;
        int j = -1;
        for (int i = 0; i < query.length() - 1; i++)
        {
            while (j >= 0 && query[i] != query[j])
            {
                j = table[j];
            }
            table[i + 1] = j + 1;
            j++;
        }
        return table;
    }
};

int main()
{
    string text, query;
    cin >> text >> query;

    StrKMP terget(text);
    vector<int> match_index;
    terget.find(query, match_index);

    for (const auto& e : match_index)
    {
        cout << e << endl;
    }
}
