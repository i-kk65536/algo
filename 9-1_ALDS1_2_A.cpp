#include<iostream>
#include<vector>
using namespace std;

int bubbleSort(vector<int>& v);

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

    int elements_exchange_times = bubbleSort(array);

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

int bubbleSort(vector<int>& v)
{
    int length = v.size();
    bool exist_left_flag = 1;
    int exchange_times = 0;
    
    while (exist_left_flag)
    {
        exist_left_flag = 0;
        for (int i = length - 1; i > 0; i--)
        {
            if (v.at(i) < v.at(i - 1))
            {
                swap(v.at(i), v.at(i - 1));
                exist_left_flag = 1;
                exchange_times++;
            }
        }
    }
    
    return exchange_times;
}

