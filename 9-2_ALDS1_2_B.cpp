#include<iostream>
#include<vector>
using namespace std;

int selectionSort(vector<int>& v);

int main(void)
{
    int length;
    cin >> length;
    vector<int> array;
    for (int i = 0; i < length; i++)
    {
        int tmp;
        cin >> tmp;
        array.emplace_back(tmp);
    }

    int elements_exchange_times = selectionSort(array);

    for (auto it = array.begin(); it != array.end(); it++)
    {
        cout << *it;
        if (it != array.end() - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    cout << elements_exchange_times << endl;
}

int selectionSort(vector<int>& v)
{
    int length = v.size();
    int exchange_times = 0;
    
    for (int i = 0; i < length; i++)
    {
        int minj = i;
        for (int j = i + 1; j < length; j++)
        {
            if (v.at(j) < v.at(minj))
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            swap(v.at(i), v.at(minj));
            exchange_times++;
        }
    }
    
    return exchange_times;
}
