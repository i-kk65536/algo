#include <iostream>
#include <vector>
using namespace std;

int margeSort(vector<int> list, size_t left, size_t right);
int marge(vector<int> list, size_t left, size_t mid, size_t right);

int main()
{

}

int marge(vector<int> list, size_t left, size_t mid, size_t right)
{
    size_t end_L = mid - left;
    size_t end_R = right - mid;
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
}

int margeSort(vector<int> list, size_t left, size_t right)
{
    int comparison_times = 0;
    if (!((left + 1) < right))
        return comparison_times;
    
    int mid = (left + right) / 2;
    comparison_times += margeSort(list, left, mid);
    comparison_times += margeSort(list, mid, right);
    comparison_times += marge(list, left, mid, right);
    return comparison_times;
}