#include <iostream>
using namespace std;

int main(void)
{
    int s_size, t_size = 0;
    cin >> s_size;
    int s[s_size];
    for (int i=0; i<s_size; i++)
    {
        cin >> s[i];
    }
    cin >> t_size;
    int t[t_size];
    for (int i=0; i<t_size; i++)
    {
        cin >> t[i];
    }

    int c_size = 0;
    for (int i=0; i<t_size; i++)
    {
        int begin = 0;
        int end = s_size - 1;
        while (begin <= end)
        {
            int middle = (begin + end) / 2;
            if (s[middle] == t[i])
            {
                c_size++;
                break;
            }
            if (s[middle] < t[i])
            {
                begin = middle + 1;
            }
            if (s[middle] > t[i])
            {
                end = middle - 1;
            }
        }
    }
    cout << c_size << endl;
}