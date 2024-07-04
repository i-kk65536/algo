#include <iostream>
#include <queue>
using namespace std;

void insert(priority_queue<int>& q, int x);
int extractMax(priority_queue<int>& q);

int main()
{
    priority_queue<int> q;
    while (true)
    {
        string cmd;
        cin >> cmd;
        
        if (cmd == "insert")
        {
            int x;
            cin >> x;
            insert(q, x);
        }
        if (cmd == "extract")
        {
            int max;
            max = extractMax(q);
            cout << max << endl;
        }
        if (cmd == "end")
        {
            break;
        }
    }
}

void insert(priority_queue<int>& q, int x)
{
    q.push(x);
}

int extractMax(priority_queue<int>& q)
{
    int max = q.top();
    q.pop();
    return max;
}