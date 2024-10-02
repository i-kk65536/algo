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
        for (int j=0; j<s_size; j++)
        {
            if (t[i] == s[j])
            {
                c_size++;
                break;
            }
        }
    }
    cout << c_size << endl;
}