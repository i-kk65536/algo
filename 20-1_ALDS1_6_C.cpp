#include <iostream>
#include <vector>
using namespace std;

struct card
{
    char pattern;
    int number;
    int default_index;
};

int partition(vector<card>& list, const int& left, const int& right)
{
    int last = list[right].number;
    int small_than_right = left - 1;
    for (int i = left; i < right; i++)
    {
        if (list[i].number <= last)
        {
            small_than_right++;
            swap(list[small_than_right], list[i]);
        }
    }
    swap(list[small_than_right + 1], list[right]);
    return small_than_right + 1;
}

void quicksort(vector<card>& list, const int& left, const int& right)
{
    if (!(left < right))
        return;

    int division_position = partition(list, left, right);
    quicksort(list, left, division_position - 1);
    quicksort(list, division_position + 1, right);
}

bool isStable(const vector<card>& list)
{
    bool stable_flag = true;

    for (int i = 1; i < list.size(); i++)
    {
        while (list[i - 1].number == list[i].number)
        {
            if (list[i - 1].default_index > list[i].default_index)
            {
                stable_flag = false;
                return stable_flag;
            }
            i++;
        }
    }

    return stable_flag;
}

int main()
{
    int size;
    cin >> size;
    vector<card> list(size);
    for (int i = 0; i < size; i++)
    {
        cin >> list[i].pattern >> list[i].number;
        list[i].default_index = i;
    }
    
    quicksort(list, 0, size - 1);

    if (isStable(list))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    for (const card& e: list)
        cout << e.pattern << " " << e.number << endl;
}
