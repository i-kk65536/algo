#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mergeSort(vector<int>& list, size_t left, size_t right_next);
int merge(vector<int>& list, size_t left, size_t mid, size_t right_next);

int main()
{
    size_t size;
    cin >> size;
    vector<int> list(size);
    for (int i = 0; i < size; i++)
    {
        cin >> list[i];
    }
    
    int comparison_times = mergeSort(list, 0, size);
    
    for (int i = 0; i < size; i++)
    {
        cout << list[i];
        if (i != size - 1)
            cout << " ";
        else
            cout << endl;
    }
    cout << comparison_times << endl;
}

int merge(vector<int>& list, size_t left, size_t mid, size_t right_next)
{
    size_t end_L = mid - left;
    size_t end_R = right_next - mid;
    vector<int> list_L(end_L + 1);
    vector<int> list_R(end_R + 1);
    for (int i = 0; i < end_L; i++)
    {
        list_L[i] = list[left + i];
    }
    for (int i = 0; i < end_R; i++)
    {
        list_R[i] = list[mid + i];
    }
    list_L[end_L] = INT_MAX;
    list_R[end_R] = INT_MAX;

    size_t index_L = 0;
    size_t index_R = 0;
    int comparison_times = 0;
    for (int i = left; i < right_next; i++)
    {
        if (list_L[index_L] <= list_R[index_R])
        {
            list[i] = list_L[index_L];
            index_L++;
        }
        else
        {
            list[i] = list_R[index_R];
            index_R++;
        }
        comparison_times++;
    }
    return comparison_times;
}

int mergeSort(vector<int>& list, size_t left, size_t right_next)
{
    int comparison_times = 0;
    if (!(left + 1 < right_next))
    {
        return comparison_times;
    }
    
    size_t mid = (left + right_next) / 2;
    comparison_times += mergeSort(list, left, mid);
    comparison_times += mergeSort(list, mid, right_next);
    comparison_times += merge(list, left, mid, right_next);
    return comparison_times;
}