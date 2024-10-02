#include <iostream>
#include <vector>
using namespace std;

bool BinarySerch(const vector<int>& list, const int& key);

int main()
{
    int list_size;
    cin >> list_size;
    vector<int> list(list_size);
    for (auto& e : list)
        cin >> e;
    int query_size;
    cin >> query_size;
    vector<int> query(query_size);
    for (auto& e : query)
        cin >> e;

    for (int i = 0; i < query_size; i++)
    {
        if (BinarySerch(list, query[i]))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
}

bool BinarySerch(const vector<int>& list, const int& key)
{
    int left = 0;
    int right = list.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (key < list[mid])
        {
            right = mid - 1;
        }
        else if (key > list[mid])
        {
            left = mid + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}