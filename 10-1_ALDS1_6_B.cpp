#include <iostream>
using namespace std;

int partition(int list[], int left, int right);

int main()
{
    int list_size;
    cin >> list_size;
    int list[list_size];
    for (int i = 0; i < list_size; i++)
    {
        cin >> list[i];
    }

    int division_position = partition(list, 0, list_size - 1);
    
    for (int i = 0; i < division_position; i++)
    {
        cout << list[i];
        if (i != division_position - 1)
            cout << " ";
    }
    cout << " [" << list[division_position] << "] ";
    for (int i = division_position + 1; i < list_size; i++)
    {
        cout << list[i];
        if (i != list_size - 1)
            cout << " ";
    }
    cout << endl;
}

int partition(int list[], int left, int right)
{
    int last = list[right];
    int small_than_right = left - 1;
    for (int j = left; j < right; j++)
    {
        if (list[j] <= last)
        {
            small_than_right++;
            swap(list[small_than_right], list[j]);
        }
    }
    swap(list[small_than_right + 1], list[right]);
    return small_than_right + 1;
}
