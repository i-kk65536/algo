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
    /*
    for (int i = 0; i < division_position; i++)
    {
        cout << list[i] << " ";
    }
    cout << "[" << list[division_position] << "]" << " ";
    for (int i = division_position + 1; i < list_size - 1; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    */
    for (int i = 0; i < list_size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int partition(int list[], int left, int right)
{
    int last = list[right];
    int little_than_right = left - 1;
    for (int j = left; j < right - 1; j++)
    {
        if (list[j] <= last)
        {
            little_than_right++;
            swap(list[little_than_right], list[j]);
        }
    }
    swap(list[little_than_right + 1], list[right]);
    return little_than_right + 1;
}